//
// Created by Kiana on 2024/5/22.
//

#include "My_Canny.h"

My_Canny::My_Canny(QObject *parent) : QObject(parent) {

}

void My_Canny::loadImage(QString path) {
    ///彩色加载
    src = imread(path.toStdString(),IMREAD_COLOR);
    if(src.empty()){
        qDebug() << "Image loading failed";
    }
}

void My_Canny::ImageConversion() {
    ///1.去除噪声
    Mat frame;
    cvtColor(src,frame,COLOR_BGR2RGB);
    Mat result;
    ///高斯滤波
    GaussianBlur(frame,result,Size(3,3),0);

    Mat gray;
    cvtColor(result, gray, cv::COLOR_BGR2GRAY);

    Mat edges;
    Canny(gray,edges,50,150);

    finish = edges;
}

const Mat &My_Canny::getFinish() const {
    return finish;
}
