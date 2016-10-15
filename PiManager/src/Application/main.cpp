//
// Created by Dawid on 04.09.2016.
//
#include <QApplication>
#include "Widgets/PiManagerWindow.hpp"


int main(int argv, char **argc) {
    QApplication app(argv, argc);

    PiManagerWindow raspberryWindow;
    raspberryWindow.setWindowState(raspberryWindow.windowState());
    raspberryWindow.showMaximized();

    return app.exec();
}