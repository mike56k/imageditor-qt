#include "colorsize.h"
#include "ui_colorsize.h"

ColorSize::ColorSize(QWidget *parent) :
    QWidget(parent),
    changeColorBtn(new QPushButton),
    slider(new QSlider),
    ui(new Ui::ColorSize),
    groupBox(new QGroupBox)
{
    ui->setupUi(this);

    QString buttonStyle = "QPushButton{border:none;background-color:rgba(255, 255, 255,100);}";
        changeColorBtn->setStyleSheet(buttonStyle);
        changeColorBtn->setIconSize(QSize(50,50));
        changeColorBtn->setMinimumSize(50,50);
        changeColorBtn->setMaximumSize(50,50);
    changeColorBtn->setIcon(QPixmap(":/icons/color-wheel.png"));
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(slider);

    vbox->addWidget(changeColorBtn);

    groupBox->setLayout(vbox);
    ui->horizontalLayout->addWidget(groupBox);
}

ColorSize::~ColorSize()
{
    delete ui;
}
