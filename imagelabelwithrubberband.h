#ifndef IMAGELABELWITHRUBBERBAND_H
#define IMAGELABELWITHRUBBERBAND_H
#include <QLabel>
#include <QRubberBand>
#include <QPoint>
#include <QMouseEvent>
#include <QInputDialog>
class ImageLabelWithRubberBand : public QLabel
{
   Q_OBJECT
public:
    explicit ImageLabelWithRubberBand(QWidget *parent = 0) : QLabel(parent), rubberBand(0) {}
    QPoint begin;
    QPoint end;
    int state = -1;
signals:
    void areaSelected();
    void drawing(int);
    void generateText(QString);
private:
   QRubberBand* rubberBand = nullptr;


   void mousePressEvent(QMouseEvent *event);
   void mouseMoveEvent(QMouseEvent *event);
   void mouseReleaseEvent(QMouseEvent *event);

};

#endif // IMAGELABELWITHRUBBERBAND_H
