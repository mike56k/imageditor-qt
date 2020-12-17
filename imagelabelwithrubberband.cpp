#include "imagelabelwithrubberband.h"


void ImageLabelWithRubberBand::mousePressEvent(QMouseEvent *event)
{
    if(cropState){
        begin = event->pos();
        if (!rubberBand) rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        rubberBand->setGeometry(QRect(begin, QSize()));
        rubberBand->show();
    }
}

void ImageLabelWithRubberBand::mouseMoveEvent(QMouseEvent *event)
{
    if(cropState){
            rubberBand->setGeometry(QRect(begin, event->pos()).normalized());
    }
}

void ImageLabelWithRubberBand::mouseReleaseEvent(QMouseEvent *event)
{
    if(cropState){
        end = event->pos();
        rubberBand->hide();
        emit areaSelected();
    }

}
