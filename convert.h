#ifndef CONVERT_H
#define CONVERT_H

#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <QImage>
#include <QDebug>
class Convert
{
public:
    Convert();
    static QImage  cvMatToQImage( const cv::Mat &inMat );
    static cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData = true );
};

#endif // CONVERT_H
