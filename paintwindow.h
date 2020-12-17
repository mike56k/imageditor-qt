#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include <QDialog>
#include "imagelabelfordrawing.h"
#include <QScrollArea>
#include <QPainter>
#include <QBrush>
#include <QPixmap>
namespace Ui {
class paintwindow;
}

class paintwindow : public QDialog
{
    Q_OBJECT

public:

    explicit paintwindow(QImage &image, QImage *imageAfterEffect, QWidget *parent = nullptr);
    ~paintwindow();
private:
    Ui::paintwindow *ui = nullptr;
    QImage image;
    QImage *imageAfterEffect = nullptr;
    ImageLabelForDrawing *label = nullptr;
    QScrollArea *scrollArea = nullptr;
    QPixmap *pixmap = nullptr;
    QPainter *painter = nullptr;
    QColor color;
    QPen pen;
    int penWidth = 2;
private slots:
    void drawPoint();
    void changeColor();
    void changePenWidth(int);
};

#endif // PAINTWINDOW_H
