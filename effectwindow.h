#ifndef EFFECTWINDOW_H
#define EFFECTWINDOW_H

#include <QDialog>
#include <QScrollArea>
#include <QLabel>
#include <QSlider>
namespace Ui {
class effectwindow;
}

class effectwindow : public QDialog
{
    Q_OBJECT

public:
    explicit effectwindow(QImage &beforeImage, QImage &afterImage, QWidget *parent = nullptr);
    explicit effectwindow(QImage &beforeImage, QImage &afterImage, QImage &beforeHistogram, QImage &afterHistogram, QWidget *parent = nullptr);
    ~effectwindow();
    QSlider *slider = nullptr;
    QImage imageAfter;
private slots:
    void onImageChanged(QImage &newImage);
    void repaintEffectWindow();
private:
    void init(QImage &afterImage, QImage &beforeImage);
    Ui::effectwindow *ui = nullptr;
    QImage imageBefore;

    QLabel *beforeImageLabel = nullptr;
    QLabel *afterImageLabel = nullptr;
    QScrollArea *beforeScrollArea = nullptr;
    QScrollArea *afterScrollArea = nullptr;

    QLabel *beforeHistogramLabel = nullptr;
    QLabel *afterHistogramLabel = nullptr;
    QScrollArea *beforeHistogramScrollArea = nullptr;
    QScrollArea *afterHistogramScrollArea = nullptr;

};

#endif // EFFECTWINDOW_H
