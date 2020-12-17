#include "imagelabelfordrawing.h"



void ImageLabelForDrawing::mousePressEvent(QMouseEvent *event)
{
    pointBefore = event->pos();
    pointAfter = event->pos();
    emit drawing();
}

void ImageLabelForDrawing::mouseMoveEvent(QMouseEvent *event)
{
    pointBefore = pointAfter;
    pointAfter = event->pos();
    emit drawing();
}

void ImageLabelForDrawing::mouseReleaseEvent(QMouseEvent *event)
{
    pointBefore = pointAfter;
    pointAfter = event->pos();
    emit drawing();
}
