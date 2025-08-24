#include "mainwindow.h"
#include "boardwindow.h"

#include <QApplication>
#include <QWidget>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    boardwindow b;

    auto *window = new MainWindow;
    window->resize(1920, 1080);
    window->move(window->screen()->geometry().center() - window->frameGeometry().center());
    window->show();
    return a.exec();
}
