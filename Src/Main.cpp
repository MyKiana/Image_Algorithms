//
// Created by Kiana on 2024/5/22.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Main.h" resolved

#include "Main.h"
#include "ui_Main.h"
#include "../M_Algorithms/My_Canny.h"


Main::Main(QWidget *parent) :
        QWidget(parent), ui(new Ui::Main) {
    ui->setupUi(this);

/*    QPixmap pixmap("../Images/123.png"); // 替换为你的图片路径
    if (!pixmap.isNull()) {
        ui->label->setPixmap(pixmap);
        ui->label->setFixedSize(pixmap.size());
        this->setFixedSize(ui->label->size());
    } else {
        // 处理加载图片失败的情况
        qDebug() << "Failed to load pixmap.";
    }*/
    My_Canny can;
    can.loadImage("../Images/123.png");
    can.ImageConversion();

    Mat frame = can.getFinish();
    if(!frame.empty()){
        qDebug() << "frame not empty";
        Mat Rgb;
        QImage img;
        if(frame.channels() == 3)
        {
            cvtColor(frame, Rgb, COLOR_BGR2RGB);
            img = QImage((const unsigned char*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols*Rgb.channels(), QImage::Format_RGB888);
        }else{
            img = QImage((const unsigned char*)(frame.data), frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_Indexed8);
        }

        QPixmap pixmap = QPixmap::fromImage(img);
        ui->label->setPixmap(pixmap);
        ui->label->setFixedSize(pixmap.size());
        this->setFixedSize(ui->label->size());
    }


}

Main::~Main() {
    delete ui;
}
