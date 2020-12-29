#ifndef COLORSIZE_H
#define COLORSIZE_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QSlider>
#include <QVBoxLayout>
namespace Ui {
class ColorSize;
}
/*!
 * \brief The ColorSize class
 * Класс представляет собой виджет, содержащий кнопку изменения цвета и слайдер для изменения размера
 */
class ColorSize : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief ColorSize создает виджет, инциализует ui элементы
     * \param parent Родительский виджет
     */
    explicit ColorSize(QWidget *parent = nullptr);
    ~ColorSize();
    /*!
     * \brief changeColorBtn кнопка изменения цвета
     */
    QPushButton *changeColorBtn = nullptr;
    /*!
     * \brief slider слайдер изменения размера
     */
    QSlider *slider = nullptr;

private:
    Ui::ColorSize *ui = nullptr;
    QGroupBox *groupBox = nullptr;
};

#endif // COLORSIZE_H
