#ifndef IMAGELABELFORDRAWING_H
#define IMAGELABELFORDRAWING_H
#include <QMouseEvent>
#include <QLabel>
#include <QPoint>

class ImageLabelForDrawing : public QLabel
{
  Q_OBJECT
public:
    explicit ImageLabelForDrawing(QWidget *parent = 0) : QLabel(parent) {}
    QPoint pointBefore;
    QPoint pointAfter;
signals:
    void drawing();
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // IMAGELABELFORDRAWING_H
