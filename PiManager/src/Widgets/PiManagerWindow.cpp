//
// Created by Dawid on 27.09.2016.
//



#include <QtWidgets/QVBoxLayout>
#include "PiManagerWindow.hpp"

PiManagerWindow::PiManagerWindow() {
    auto *mFunctionsView = new FunctionsWidget(0);
    auto *raspberryControlButtons = new ControlButtons(0);

    setUpWidget(mFunctionsView, raspberryControlButtons);

}

void PiManagerWindow::setUpWidget(FunctionsWidget *mFunctionsView, ControlButtons *raspberryControlButtons) {
    QVBoxLayout *verticalLayout = new QVBoxLayout;
    verticalLayout->addWidget(mFunctionsView);
    verticalLayout->addWidget(raspberryControlButtons);

    auto *mainWidget = new QWidget;
    mainWidget->setLayout(verticalLayout);

    setCentralWidget(mainWidget);
}
