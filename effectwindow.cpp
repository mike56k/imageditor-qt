#include "effectwindow.h"
#include "ui_effectwindow.h"
#include <QSlider>
#include <QLabel>
#include <QScreen>

effectwindow::effectwindow(QImage &beforeImage, QImage &afterImage, QWidget *parent)  :
    QDialog(parent),
    slider(new QSlider(Qt::Horizontal)),
    ui(new Ui::effectwindow)
{
    init(afterImage, beforeImage);
    ui->verticalLayout->addWidget(slider);
    afterScrollArea->setWidgetResizable(true);
    ui->verticalLayout->addWidget(beforeScrollArea);
    ui->verticalLayout->addWidget(afterScrollArea);
}
effectwindow::effectwindow(QImage &beforeImage, QImage &afterImage, QImage &beforeHistogram, QImage &afterHistogram, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::effectwindow),
    beforeHistogramLabel(new QLabel),
    afterHistogramLabel(new QLabel),
    beforeHistogramScrollArea(new QScrollArea),
    afterHistogramScrollArea(new QScrollArea)
{
    QGridLayout *layout = new QGridLayout;
    init(afterImage, beforeImage);
    beforeHistogramScrollArea->setBackgroundRole(QPalette::Dark);
    afterHistogramScrollArea->setBackgroundRole(QPalette::Dark);
    beforeHistogramLabel->setPixmap(QPixmap::fromImage(beforeHistogram));
    afterHistogramLabel->setPixmap(QPixmap::fromImage(afterHistogram));
    beforeHistogramScrollArea->setWidget(beforeHistogramLabel);
    afterHistogramScrollArea->setWidget(afterHistogramLabel);
    layout->addWidget(beforeScrollArea, 0, 0);
    layout->addWidget(beforeHistogramScrollArea, 0, 1);
    layout->addWidget(afterScrollArea, 1, 0);
    layout->addWidget(afterHistogramScrollArea, 1, 1);
    ui->verticalLayout->addLayout(layout);
}
effectwindow::~effectwindow()
{
    delete ui;
}
void effectwindow::onImageChanged(QImage &newImage){
    imageAfter = newImage;
    repaintEffectWindow();
}
void effectwindow::repaintEffectWindow(){
    beforeImageLabel->setPixmap(QPixmap::fromImage(imageBefore));
    afterImageLabel->setPixmap(QPixmap::fromImage(imageAfter));
    beforeScrollArea->setWidget(beforeImageLabel);
    afterScrollArea->setWidget(afterImageLabel);
}
void effectwindow::init(QImage &afterImage, QImage &beforeImage)
{
    ui->setupUi(this);
    setWindowIcon(QPixmap(":/icons/effects.png"));
    beforeImageLabel = new QLabel;
    afterImageLabel = new QLabel;
    beforeScrollArea = new QScrollArea;
    afterScrollArea = new QScrollArea;
    beforeScrollArea->setBackgroundRole(QPalette::Dark);
    afterScrollArea->setBackgroundRole(QPalette::Dark);
    setWindowTitle(tr("Effect Preview"));
    QObject::connect(ui->acceptButton, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
    resize(QGuiApplication::primaryScreen()->availableSize() * 1 / 2);
    imageAfter = afterImage;
    imageBefore = beforeImage;
    repaintEffectWindow();
}
