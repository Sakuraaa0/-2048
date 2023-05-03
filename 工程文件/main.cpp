#include "welcome.h"
#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));//随机数种子
    QApplication a(argc, argv);
    Welcome w;
    w.show();

    return a.exec();
}
