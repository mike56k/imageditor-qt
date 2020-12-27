#include "imagelabelwithrubberband.h"


void ImageLabelWithRubberBand::mousePressEvent(QMouseEvent *event)
{
    switch (state) {
    case 0: {
        begin = event->pos();
        if (!rubberBand) rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        rubberBand->setGeometry(QRect(begin, QSize()));
        rubberBand->show();
        break;
    }
    case 1: {
        begin = event->pos();
        end = event->pos();
        emit drawing(0);
        break;
    }
    case 2: {
        begin = event->pos();
        QString text = QInputDialog::getText(this, tr("Text Shape"),
                                             tr("Enter text:"),
                                             QLineEdit::Normal, tr("Some Text"));
        emit generateText(text);
        break;
    }
    default:
        break;
    }
}

void ImageLabelWithRubberBand::mouseMoveEvent(QMouseEvent *event)
{
    switch (state) {
        case 0:
            rubberBand->setGeometry(QRect(begin, event->pos()).normalized());
            break;
        case 1:
            begin = end;
            end = event->pos();
            emit drawing(1);
            break;
        default:
            break;
    }

}

void ImageLabelWithRubberBand::mouseReleaseEvent(QMouseEvent *event)
{
    switch (state) {
        case 0:
            end = event->pos();
            rubberBand->hide();
            emit areaSelected();
            break;
        case 1:
            begin = end;
            end = event->pos();
            emit drawing(2);
            break;
        default:
            break;
    }

}
