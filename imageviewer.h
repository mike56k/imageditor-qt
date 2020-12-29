
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
#include <QPen>
#include <QColorDialog>
#include <QPainter>
#include <QLayout>
#include "colorsize.h"
#include <QMenuBar>
#include <QMessageBox>
#include <QMimeData>
#include <QScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QStandardPaths>
#include <QStatusBar>
#include <QObject>
#include <QToolBar>
#include <effectwindow.h>
#include <QDockWidget>
#include <QPainterPath>

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
    /*!
     * \brief open Срабатывает при нажатии на кнопку открытия файла,
     * открывает файловое окно, передает полученный путь в loadFile
     */
    void open();
    /*!
     * \brief saveAs Срабатывает при нажатии на кнопку сохранения файла,
     * открывает файловое окно, передает полученный путь в saveFile
     */
    void saveAs();
    void copy();
    void paste();
    /*!
     * \brief zoomIn приближает изображение
     */
    void zoomIn();
    /*!
     * \brief zoomOut отдаляет изображение
     */
    void zoomOut();
    /*!
     * \brief normalSize восстанавливает исходный масштаб изображения
     */
    void normalSize();
    /*!
     * \brief fitToWindow растягивает изображение по ширине окна
     */
    void fitToWindow();

    void crop();
    void paint();
    void showSelectedArea();
    void paintPoint(int val);
    void paintText(QString);
    void showBrightnessEffect();
    void showSepia();
    void showHistogramEqualization();
    void showHomogeneousEffect();
    void showGaussianEffect();
    void showMedianEffect();
    void showBilateralEffect();
    void brightnessAlgorithm();
    /*!
     * \brief homogeneousAlgorithm Применяет гомогенное размытие
     */
    void homogeneousAlgorithm();
    /*!
     * \brief gaussianAlgorithm Применяет гауссово размытие
     */
    void gaussianAlgorithm();
    /*!
     * \brief medianAlgorithm Применяет медианный алгоритм размытия
     */
    void medianAlgorithm();
    /*!
     * \brief bilateralAlgorithm Применяет двусторонний алгоритм размытия
     */
    void bilateralAlgorithm();
    /*!
     * \brief dialogIsFinished Слот, который срабатывает в момент закрытия окна эффектов.
     * Если пользователь принял изменения, то добавляет измененное изображение в стэк сделанных действий.
     */
    void dialogIsFinished(int);
    /*!
     * \brief changeColor Слот, который срабатывает при нажатии на кнопку изменения цвета.
     * Устанавливает цвет кисти.
     */
    void changeColor();
    void changePenWidth(int);
    void addText();
    void closeEvent(QCloseEvent *event);
signals:
    void imageChanged();
private:
    void createActions();
    void createMenus();
    void updateActions();
    void initColorSizeWidget(QString);
    bool saveFile(const QString &fileName);

    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    /*!
     * \brief changeImage сообщает об изменении изображения, после чего окно эффектов перерисовывается.
     * \param newImage Новое изображение, полученное после применения эффекта к старому изображению.
     */
    void changeImage(QImage &newImage);
    cv::Mat generateHistogram(const cv::Mat& inputImage);
    QImage image;
    QImage imageAfterEffect;
    QPixmap *pixmapForPainting = nullptr;
    QPainter *painter = nullptr;
    QPen pen;
    QColor color;
    int penWidth = 0;
    ImageLabelWithRubberBand *imageLabel = nullptr;
    QScrollArea *scrollArea = nullptr;
    double scaleFactor = 1;
    /*!
     * \brief countOfScales Количество приближений. Используется для контроля приближения и отдаления изображения.
     * Если равно нулю, то изображение находится в исходном положении.
     * Если меньше нуля, то отдалено.
     * Если больше нуля, то приближено.
     */
    int countOfScales = 0;

    QAction *saveAsAct = nullptr;
    QAction *copyAct = nullptr;
    QAction *zoomInAct = nullptr;
    QAction *zoomOutAct = nullptr;
    QAction *normalSizeAct = nullptr;
    QAction *fitToWindowAct = nullptr;
    QAction *openAct = nullptr;
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
    QAction *changeColorAct = nullptr;
    effectwindow *w = nullptr;
    QDockWidget *dockWidget = nullptr;
    QUndoStack *undoStack = nullptr;
    QAction *addTextAct = nullptr;
};

#endif
