#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include <imageviewer.h>
/*!
 * \brief The AddCommand class наследуется от QUndoCommand.
 * Дает возможность отменять совершенные пользователем действия.
 */
class AddCommand : public QUndoCommand
{
public:
    /*!
     * \brief AddCommand устанавливает поля image и imageBefore.
     * Устанавливает изображение после совершения действия в главную форму.
     * \param image изображение после действия
     * \param imageBefore изображение до совершения действия
     * \param mainWindow указатель на главную форму
     * \param parent
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
