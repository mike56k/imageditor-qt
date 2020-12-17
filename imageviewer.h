
#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QImage>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <convert.h>
#include <QUndoStack>
#include <QUndoCommand>
#include "effectwindow.h"
#include "imagelabelwithrubberband.h"
#include "paintwindow.h"
#if defined(QT_PRINTSUPPORT_LIB)
#endif

QT_BEGIN_NAMESPACE
class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
QT_END_NAMESPACE


class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    bool loadFile(const QString &);
    QToolBar* createToolBar();
    void setImage(const QImage &newImage);
private slots:
    void open();
    void saveAs();
    void copy();
    void paste();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();
    void crop();
    void paint();
    void showSelectedArea();

    void showBrightnessEffect();
    void showSepia();
    void showHistogramEqualization();
    void showHomogeneousEffect();
    void showGaussianEffect();
    void showMedianEffect();
    void showBilateralEffect();
    void brightnessAlgorithm(int);
    void homogeneousAlgorithm(int);
    void gaussianAlgorithm(int);
    void medianAlgorithm(int);
    void bilateralAlgorithm(int);
    void dialogIsFinished(int);

signals:
    void imageChanged();
private:
    void createActions();
    void createMenus();
    void updateActions();
    bool saveFile(const QString &fileName);

    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    void changeImage(QImage &newImage);
    cv::Mat generateHistogram(const cv::Mat& inputImage);
    QImage image;
    QImage imageAfterEffect;
    ImageLabelWithRubberBand *imageLabel = nullptr;
    QScrollArea *scrollArea = nullptr;
    double scaleFactor = 1;
    QAction *saveAsAct = nullptr;
    QAction *copyAct = nullptr;
    QAction *zoomInAct = nullptr;
    QAction *zoomOutAct = nullptr;
    QAction *normalSizeAct = nullptr;
    QAction *fitToWindowAct = nullptr;

    QAction *brightnessAct = nullptr;
    QAction *blurHAct = nullptr;
    QAction *blurGAct = nullptr;
    QAction *blurMAct = nullptr;
    QAction *blurBAct = nullptr;
    QAction *histAct = nullptr;
    QAction *sepiaAct = nullptr;

    QAction *undoAction = nullptr;
    QAction *redoAction = nullptr;

    QAction *cropAct = nullptr;
    QAction *paintAct = nullptr;

    effectwindow *w = nullptr;
    paintwindow *pw = nullptr;

    QUndoStack *undoStack = nullptr;
};

#endif
