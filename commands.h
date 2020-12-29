#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include <imageviewer.h>
/*!
 * \brief The AddCommand class наследуется от QUndoCommand.
 * Дает возможность записывать пользовательские действия в стэк.
 */
class AddCommand : public QUndoCommand
{
public:
    /*!
     * \brief устанавливает поля image (изображение после совершения какого-либо действия) и
     *  imageBefore (изображение до совершения какого-либо действия).
     *  Устанавливает изображение после совершения действия в главную форму.
     * \param image изображение после действия
     * \param imageBefore изображение до совершения действия
     * \param mainWindow указатель на главную форму
     * \param parent экзэмпляр родительского класса
     */
    AddCommand(QImage &image, QImage &imageBefore, ImageViewer *mainWindow,
               QUndoCommand *parent = nullptr);
    /*!
     * \brief undo Отменяет выполненное действие.
     * Устанавливает в главное окно ImageViewer изображение imageBefore
     */
    void undo() override;
    /*!
     * \brief redo Возвращает выполенное действие после его отмены.
     * Устанавливает в главное окно ImageViewer изображение image.
     */
    void redo() override;

private:
    QImage image;
    QImage imageBefore;
    ImageViewer *imageViewer = nullptr;
};

#endif
