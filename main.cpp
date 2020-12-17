
#include <QApplication>

#include "imageviewer.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    QGuiApplication::setApplicationDisplayName(ImageViewer::tr("Image Editor"));
    ImageViewer imageViewer;
    imageViewer.show();
    return app.exec();
}
