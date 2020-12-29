#include "convert.h"


cv::Mat Convert::QImageToCvMat(const QImage &inImage)
{
    switch ( inImage.format() )
    {
       /// 8-бит, 4 канала
       case QImage::Format_ARGB32:
       case QImage::Format_ARGB32_Premultiplied:
       {
          cv::Mat  mat( inImage.height(), inImage.width(),
                        CV_8UC4,
                        const_cast<uchar*>(inImage.bits()),
                        static_cast<size_t>(inImage.bytesPerLine())
                        );

          return mat;
       }

       /// 8-бит, 3 канала
       case QImage::Format_RGB32:
       {

          cv::Mat  mat( inImage.height(), inImage.width(),
                        CV_8UC4,
                        const_cast<uchar*>(inImage.bits()),
                        static_cast<size_t>(inImage.bytesPerLine())
                        );

          cv::Mat  matNoAlpha;

          cv::cvtColor( mat, matNoAlpha, cv::COLOR_BGRA2BGR );   // drop the all-white alpha channel

          return matNoAlpha;
       }

       // 8-bit, 3 channel
       case QImage::Format_RGB888:
       {


          QImage   swapped = inImage.rgbSwapped();

          return cv::Mat( swapped.height(), swapped.width(),
                          CV_8UC3,
                          const_cast<uchar*>(swapped.bits()),
                          static_cast<size_t>(swapped.bytesPerLine())
                          ).clone();
       }

       // 8-bit, 1 channel
       case QImage::Format_Indexed8:
       {
          cv::Mat  mat( inImage.height(), inImage.width(),
                        CV_8UC1,
                        const_cast<uchar*>(inImage.bits()),
                        static_cast<size_t>(inImage.bytesPerLine())
                        );

          return mat;
       }

       default:
          qWarning() << "ASM::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
          break;
    }

    return cv::Mat();
}


QImage Convert::cvMatToQImage(const cv::Mat &inMat)
{
    switch ( inMat.type() )
    {
       /// 8-бит, 4 канала
       case CV_8UC4:
       {
          QImage image( inMat.data,
                        inMat.cols, inMat.rows,
                        static_cast<int>(inMat.step),
                        QImage::Format_ARGB32 );

          return image;
       }

       /// 8-бит, 3 канала
       case CV_8UC3:
       {
          QImage image( inMat.data,
                        inMat.cols, inMat.rows,
                        static_cast<int>(inMat.step),
                        QImage::Format_RGB888 );

          return image.rgbSwapped();
       }

       /// 8-бит, 1 канал
       case CV_8UC1:
       {

          QImage image( inMat.data,
                        inMat.cols, inMat.rows,
                        static_cast<int>(inMat.step),
                        QImage::Format_Grayscale8 );


          return image;
       }

       default:
          qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
          break;
    }

    return QImage();
}
