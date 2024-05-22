//
// Created by Kiana on 2024/5/22.
//

#ifndef IMAGE_ALGORITHMS_MY_CANNY_H
#define IMAGE_ALGORITHMS_MY_CANNY_H

#include <QDebug>

#include <opencv2/imgproc.hpp>    //图像处理模块
#include <opencv2/opencv.hpp>

using namespace cv;

class My_Canny : public QObject {
    Q_OBJECT
public:
    My_Canny(QObject *parent = nullptr);

    void loadImage(QString path);

    void ImageConversion();

    const Mat &getFinish() const;

private:
    Mat src;

    Mat finish;

};

#endif //IMAGE_ALGORITHMS_MY_CANNY_H
