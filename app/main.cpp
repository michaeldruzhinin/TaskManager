
#include <windows.h>
#include <QApplication>
#include "../gui/mainwindow.h"
int main(int argc, char *argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

