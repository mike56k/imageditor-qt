
#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QImage>




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

/*!
 * \brief The ImageViewer class представляет собой главную форму со всеми инструментами для взаимодействия с изображениями.
 */
class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief ImageViewer устанавливает начальные параметры главного окна и изображения в нем, создает стэк действий.
     * \param parent Родительский виджет
     */
    ImageViewer(QWidget *parent = nullptr);
    /*!
     * \brief setImage устанавливает изображение в ImageLabelWithRubberBand,
     * делает активным основные инструменты, соединяет сигнал изменения изображения со слотом перерисовки окно эффектов,
     * соединяет сигнал завершения окна эффектов с методом dialogIsFinished(int),
     * устанавливает начальные значения масштаба.
     * \param newImage
     */
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
    /*!
     * \brief copy загружает изображение в буффер обмена
     */
    void copy();
    /*!
     * \brief paste устанавливает изображение из буффера обмена в главное окно
     */
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
    /*!
     * \brief crop устанавливает imageLabel в режим обрезки и отключает его при повторном нажатии.
     * После этого обновляет состояния всех кнопок.
     */
    void crop();
    /*!
     * \brief paint устанавливает imageLabel в режим рисования и отключает его при повторном нажатии.
     * Вызывает метод, инициализирующий виджет для изменения цвета и размера кисти.
     */
    void paint();
    /*!
     * \brief showSelectedArea открывает effectwindow, в котором измененной картинкой является обрезанное изображение,
     * поверяет, чтобы выделенная область не выходила за границы изображения
     */
    void showSelectedArea();
    /*!
     * \brief paintPoint рисует линию на изображении по двум точкам, координаты которых берутся из
     * объекта класса ImageLabelWithRubberBand в режиме рисования. Если val равен 2
     * сохраняет нарисованную линию в стэк действий.
     * \param val отвечает за статус рисования, если val равен 2, значит линия дорисована
     */
    void paintPoint(int val);
    /*!
     * \brief paintText рисует текст на изображении, координаты которого берутся из
     * объекта класса ImageLabelWithRubberBand в режиме наложения текста
     * \param text текст приходящий из сигнала класса ImageLabelWithRubberBand
     */
    void paintText(QString text);
    /*!
     * \brief showBrightnessEffect открывает effectwindow, в котором измененной картинкой является изображение с измененной яркостью
     */
    void showBrightnessEffect();
    /*!
     * \brief showSepia открывает effectwindow, в котором измененной картинкой является изображение с эффектом сепии
     */
    void showSepia();
    /*!
     * \brief showHistogramEqualization открывает effectwindow с двумя гистограммами, измененной картинкой
     *  является изображение с эквализированной гистограммой
     */
    void showHistogramEqualization();
    /*!
     * \brief showHomogeneousEffect открывает effectwindow, в котором измененной картинкой является
     *  изображение с эффектом гомогенного размытия
     */
    void showHomogeneousEffect();
    /*!
     * \brief showGaussianEffect открывает effectwindow, в котором измененной картинкой является
     *  изображение с эффектом гауссова размытия,
     *  соединяет слайдер окна эффектов с методом homogeneousAlgorithm
     */
    void showGaussianEffect();
    /*!
     * \brief showMedianEffect открывает effectwindow, в котором измененной картинкой является
     *  изображение с эффектом медианного размытия
     */
    void showMedianEffect();
    /*!
     * \brief showBilateralEffect открывает effectwindow, в котором измененной картинкой является
     *  изображение с эффектом двустороннего размытия
     */
    void showBilateralEffect();
    /*!
     * \brief brightnessAlgorithm Применяет алгоритм увелчичения яркости к текущему изображению
     */
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
    /*!
     * \brief changePenWidth изменяет размер кисти
     */
    void changePenWidth(int);
    /*!
     * \brief addText включает режим добавления текста, добавляет в форму виджет изменения цвета и размера текста
     */
    void addText();
    /*!
     * \brief closeEvent перегруженный слот закрытия формы. Предлагает сохранить изображение перед закрытием приложения
     * \param event Событие закрытия формы
     */
    void closeEvent(QCloseEvent *event);
signals:
    /*!
     * \brief imageChanged сообщает об изменении изображения. Используется для перерисовки виджета с эффектом.
     */
    void imageChanged();
private:
    /*!
     * \brief createActions создает меню, секции меню, устнавливает иконки для всех QAction.
     */
    void createActions();
    /*!
     * \brief loadFile загружает изображение в программу
     * \param fileName путь до изображения
     * \return в случае успешной загрузки возвращает true, иначе false
     */
    bool loadFile(const QString &fileName);
    /*!
     * \brief updateActions обновляет все кнопки в соответсвии с возможностью ими пользоваться
     * в той или иной ситуации
     */
    void updateActions();
    /*!
     * \brief createToolBar создает ToolBar с необходимыми инструментами
     * \return возвращает указатель на созданный ToolBar
     */
    QToolBar* createToolBar();
    /*!
     * \brief initColorSizeWidget инициализирует виджет ColorSize, связывает его кнопку изменения цвета с
     * методом changeColor, его слайдер с методом changePenWidth. Добавляет ColorSize виджет в QDockWidget,
     * который добавляется в главную форму
     */
    void initColorSizeWidget(QString);
    /*!
     * \brief saveFile сохраняет изображение в одном из необходимых пользователю форматах по заданному пути директории
     * \param fileName путь директории сохранения файла
     * \return
     */
    bool saveFile(const QString &fileName);
    /*!
     * \brief scaleImage увеличивает масштаб изображения в factor раз, устанавливает подходящие значения для ScrollBar
     * \param factor коэффициент увеличения или уменьшения масштаба изображения
     */
    void scaleImage(double factor);
    /*!
     * \brief adjustScrollBar устанавливает подходящее значение для scrollBar в зависимости от масштаба изображения
     * \param scrollBar
     * \param factor
     */
    void adjustScrollBar(QScrollBar *scrollBar, double factor);
    /*!
     * \brief changeImage сообщает об изменении изображения, после чего окно эффектов перерисовывается.
     * \param newImage Новое изображение, полученное после применения эффекта к старому изображению.
     */
    void changeImage(QImage &newImage);
    /*!
     * \brief generateHistogram генерирует гистограмму с использованием фукнций OpenCV
     * \param inputImage Изображение, из которого небходимо сгенерировать гистограмму
     * \return
     */
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
    ColorSize *colorSizeWidget = nullptr;
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
