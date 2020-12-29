#ifndef CONVERT_H
#define CONVERT_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <QImage>
#include <QDebug>

/*!
 * \brief The Convert class собирает в себе статические методы
 * для конвертации изображений в различные форматы, используемые
 * в проекте.
 */
class Convert
{
public:
    Convert() = default;
    /*!
     * \brief cvMatToQImage Конвертирует cv::Mat в QImage
     * \param inMat
     * \return Возвращает QImage
     */
    static QImage  cvMatToQImage( const cv::Mat &inMat );
    /*!
     * \brief QImageToCvMat Конвертирует QImage в cv::Mat
     * \param inImage
     * \return Возвращает cv::Mat
     */
    static cv::Mat QImageToCvMat( const QImage &inImage);
};

#endif // CONVERT_H
