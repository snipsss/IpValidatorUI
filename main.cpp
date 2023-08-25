#include "mainwindow.h"
#include "TableCls.h"
#include <QApplication>
#include "ReadFromFile.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //ReadFromFile("C:\\Users\\acer\\Desktop\\FileDescr\\FileDescriptor\\FileDescriptor\\ipList.txt");

    Table *window = new Table;
    window->showFullScreen();

    return a.exec();
}
