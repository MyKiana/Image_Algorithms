#include <QApplication>
#include <QPushButton>
#include "Src/Main.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Main ma;
    ma.show();

    return QApplication::exec();
}
