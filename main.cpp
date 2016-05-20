#include "mainwindow.h"
#include "Card.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    Card card(DIAMOND, NINE);
    std::cout << card.toString() << std::endl;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
