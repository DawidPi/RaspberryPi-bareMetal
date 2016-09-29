//
// Created by Dawid on 27.09.2016.
//



#include <QtWidgets/QHBoxLayout>
#include "PiManagerWindow.h"

PiManagerWindow::PiManagerWindow() :
        mRaspberryControlButtons(new ControlButtons) {
    QWidget *mainWidget = new QWidget;
    QHBoxLayout *horizontalLayout = new QHBoxLayout;
    horizontalLayout->addWidget(mRaspberryControlButtons);
    mainWidget->setLayout(horizontalLayout);
    setCentralWidget(mainWidget);
}
