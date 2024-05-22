//
// Created by Kiana on 2024/5/22.
//

#ifndef IMAGE_ALGORITHMS_MAIN_H
#define IMAGE_ALGORITHMS_MAIN_H

#include <QWidget>
#include <QDebug>
#include <QPixmap>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class Main; }
QT_END_NAMESPACE

class Main : public QWidget {
Q_OBJECT

public:
    explicit Main(QWidget *parent = nullptr);

    ~Main() override;

private:
    Ui::Main *ui;
};


#endif //IMAGE_ALGORITHMS_MAIN_H
