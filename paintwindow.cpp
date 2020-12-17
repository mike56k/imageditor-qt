#include "paintwindow.h"
#include "ui_paintwindow.h"
#include "iostream"
#include <QGraphicsEllipseItem>
#include <QScreen>
#include <QPushButton>
#include <QColorDialog>
#include <QSlider>

paintwindow::paintwindow(QImage &image, QImage *imageAfterEffect, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paintwindow),
    label(new ImageLabelForDrawing),
    scrollArea(new QScrollArea)
{
    ui->setupUi(this);
    resize(QGuiApplication::primaryScreen()->availableSize() * 1 / 2);
    this->image = image;
    this->imageAfterEffect = imageAfterEffect;
    pixmap = new QPixmap(QPixmap::fromImage(this->image));
    label->setPixmap(QPixmap::fromImage(image));
    scrollArea->setWidget(label);
    QPushButton *acceptButton = new QPushButton("Accept");
    QPushButton *cancelButton = new QPushButton("Cancel");
    QPushButton *changeColorButton = new QPushButton("Change Color");
    QSlider *slider = new QSlider(Qt::Horizontal);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(acceptButton);
    layout->addWidget(cancelButton);
    layout->addWidget(changeColorButton);
    layout->addWidget(slider);
    ui->verticalLayout->addLayout(layout);
    QObject::connect(acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    QObject::connect(changeColorButton, SIGNAL(clicked()), this, SLOT(changeColor()));
    ui->verticalLayout->addWidget(scrollArea);
    QObject::connect(label, SIGNAL(drawing()),this, SLOT(drawPoint()));
    QObject::connect(slider, SIGNAL(valueChanged(int)), this, SLOT(changePenWidth(int)));
    painter = new QPainter(pixmap);
    painter->setRenderHint(QPainter::Antialiasing);
    pen.setColor(color);
    pen.setWidth(penWidth);
    painter->setPen(pen);
}

paintwindow::~paintwindow()
{
    delete ui;
}

void paintwindow::drawPoint()
{
    painter->setPen(pen);
    painter->drawLine(label->pointBefore, label->pointAfter);
    label->setPixmap(*pixmap);
    *imageAfterEffect = pixmap->toImage();
}

void paintwindow::changeColor(){
    color = QColorDialog::getColor();
    pen.setColor(color);
}

void paintwindow::changePenWidth(int n)
{
    penWidth = n + 2;
    pen.setWidth(penWidth);
}
