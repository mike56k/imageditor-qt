#include "convert.h"

cv::Mat Convert::QImageToCvMat(const QImage &inImage)
{
    switch ( inImage.format() )
    {
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

       case QImage::Format_RGB888:
       {


          QImage   swapped = inImage.rgbSwapped();

          return cv::Mat( swapped.height(), swapped.width(),
                          CV_8UC3,
                          const_cast<uchar*>(swapped.bits()),
                          static_cast<size_t>(swapped.bytesPerLine())
                          ).clone();
       }

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
       case CV_8UC4:
       {
          QImage image( inMat.data,
                        inMat.cols, inMat.rows,
                        static_cast<int>(inMat.step),
                        QImage::Format_ARGB32 );

          return image;
       }

       case CV_8UC3:
       {
          QImage image( inMat.data,
                        inMat.cols, inMat.rows,
                        static_cast<int>(inMat.step),
                        QImage::Format_RGB888 );

          return image.rgbSwapped();
       }
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
