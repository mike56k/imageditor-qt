#include "commands.h"

AddCommand::AddCommand(QImage &image, QImage &imageBefore, ImageViewer *mainWindow, QUndoCommand *parent)
    : QUndoCommand(parent), imageViewer(mainWindow)
{

    this->image = image;
    this->imageBefore = imageBefore;
    imageViewer->setImage(image);
}

void AddCommand::undo()
{
    imageViewer->setImage(imageBefore);

}
void AddCommand::redo()
{
    imageViewer->setImage(image);
}



