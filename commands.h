#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include <imageviewer.h>
class AddCommand : public QUndoCommand
{
public:
    AddCommand(QImage &image, QImage &imageBefore, ImageViewer *mainWindow,
               QUndoCommand *parent = nullptr);
    void undo() override;
    void redo() override;

private:
    QImage image;
    QImage imageBefore;
    ImageViewer *imageViewer = nullptr;

};

#endif
