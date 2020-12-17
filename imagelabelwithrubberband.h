#ifndef IMAGELABELWITHRUBBERBAND_H
#define IMAGELABELWITHRUBBERBAND_H
#include <QLabel>
#include <QRubberBand>
#include <QPoint>
#include <QMouseEvent>
class ImageLabelWithRubberBand : public QLabel
{
   Q_OBJECT
public:
    explicit ImageLabelWithRubberBand(QWidget *parent = 0) : QLabel(parent), rubberBand(0) {}
    QPoint begin;
    QPoint end;
    bool cropState = false;
signals:
    void areaSelected();
private:
   QRubberBand* rubberBand = nullptr;


   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);

};

#endif // IMAGELABELWITHRUBBERBAND_H
