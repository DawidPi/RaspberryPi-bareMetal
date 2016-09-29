//
// Created by Dawid on 04.09.2016.
//
#include <QApplication>
#include "Widgets/PiManagerWindow.h"


int main(int argv, char **argc) {
    QApplication app(argv, argc);

    PiManagerWindow raspberryWindow;
    raspberryWindow.show();

    return app.exec();
}