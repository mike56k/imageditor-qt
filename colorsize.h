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

class ColorSize : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSize(QWidget *parent = nullptr);
    ~ColorSize();
    QPushButton *changeColorBtn = nullptr;
    QSlider *slider = nullptr;

private:
    Ui::ColorSize *ui = nullptr;
    QGroupBox *groupBox = nullptr;
};

#endif // COLORSIZE_H
