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
    /*!
     * \brief begin Координаты начала обрезки/рисования/текста
     */
    QPoint begin;
    /*!
     * \brief end Координаты конца обрезки/последующей точки при рисовании
     */
    QPoint end;
    /*!
     * \brief state Состояние редактора
     * -1, если ни один из режимов не включен.
     * 0, если режим обрезки
     * 1, если режим рисования
     * 2, если режим наложения текста
     */
    int state = -1;
signals:
    /*!
     * \brief areaSelected Сигнал о завершении выделения
     */
    void areaSelected();
    /*!
     * \brief drawing Сигнал об обновлении полей begin и end.
     * Если передает 0 в параметре, значит линия начата.
     * Если передает 1 в параметре, значит линия рисуется.
     * Если передает 2 в параметре, значит линия нарисована.
     */
    void drawing(int);
    /*!
     * \brief generateText Сигнал о получении текста из диалогового окна
     * и установки координаты размещения этого текста.
     */
    void generateText(QString);
private:
   QRubberBand* rubberBand = nullptr;

   /*!
    * \brief mousePressEvent
    * Обработчик события нажатия, который:
    * 1) Инициализирует параметры для обрезки изображения
    * 2) Инициализирует параметры для рисования
    * 3) Устанавливает координаты наложенного текста и вызывает текстовое окно
    * \param event
   */
   void mousePressEvent(QMouseEvent *event);
   /*!
    * \brief mouseMoveEvent
    * 1) устанавливает выделенную область при движении в режиме обрезки
    * 2) устанавливает координаты новой точки в режиме рисования
    * \param event
    */
   void mouseMoveEvent(QMouseEvent *event);
   /*!
    * \brief mouseReleaseEvent
    * 1) Отправляет выделенную область в режиме обрезки
    * 2) Устанавливает финальную точку в режиме рисования, сообщает о завершении
    * \param event
    */
   void mouseReleaseEvent(QMouseEvent *event);

};

#endif // IMAGELABELWITHRUBBERBAND_H
