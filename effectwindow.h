#ifndef EFFECTWINDOW_H
#define EFFECTWINDOW_H

#include <QDialog>
#include <QScrollArea>
#include <QLabel>
#include <QSlider>
namespace Ui {
class effectwindow;
}
/*!
 * \brief The effectwindow class наследуется от QDialog, служит для предпросмотра примененного к изображению эффекта.
 */
class effectwindow : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief effectwindow Конструктор класса effectwindow. Создает форму с двумя изображениями "до" и "после" эффекта.
     * \param beforeImage Изображение до эффекта.
     * \param afterImage Изображение после эффекта.
     * \param parent
     */
    explicit effectwindow(QImage &beforeImage, QImage &afterImage, QWidget *parent = nullptr);
    /*!
     * \brief effectwindow Конструктор класса effectwindow.
     * Создает форму с двумя изображениями "до" и "после" эффекта и двумя гистограммами этих изображений.
     * \param beforeImage Изображение до эффекта.
     * \param afterImage Изображение после эффекта.
     * \param beforeHistogram Гистограмма изображения до эффекта.
     * \param afterHistogram Гистограмма изображения после эффекта.
     * \param parent
     */
    explicit effectwindow(QImage &beforeImage, QImage &afterImage, QImage &beforeHistogram, QImage &afterHistogram, QWidget *parent = nullptr);
    ~effectwindow();
    /*!
     * \brief slider слайдер изменения интенсивности эффекта
     */
    QSlider *slider = nullptr;
    /*!
     * \brief imageAfter изображение после эффекта
     */
    QImage imageAfter;
private slots:
    /*!
     * \brief repaintEffectWindow Данный слот изменяет изображения в окне эффектов.
     */
    void repaintEffectWindow();
private:
    /*!
     * \brief init Функция для инициализацию форм с двумя изображениями.
     * \param afterImage Изображение после эффекта.
     * \param beforeImage Изображение до эффекта.
     */
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
