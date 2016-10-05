//
// Created by Dawid on 27.09.2016.
//



#include <QtWidgets/QVBoxLayout>
#include "PiManagerWindow.hpp"
#include "LogsWidget.hpp"
#include <QtWidgets/QDockWidget>

PiManagerWindow::PiManagerWindow() {
    auto *mFunctionsView = new FunctionsWidget(0);
    auto *raspberryControlButtons = new ControlButtons(0);

    setUpWidget(mFunctionsView, raspberryControlButtons);

}

void PiManagerWindow::setUpWidget(FunctionsWidget *mFunctionsView, ControlButtons *raspberryControlButtons) {
    auto *verticalLayout = new QVBoxLayout;
    auto *horizontalLayout = new QHBoxLayout;
    auto *dockFunctionsWidget = new QDockWidget;
    auto *dockControlButtons = new QDockWidget;
    dockFunctionsWidget->setWidget(mFunctionsView);

    addDockWidget(Qt::LeftDockWidgetArea, dockFunctionsWidget);
    disableCloseButton(dockFunctionsWidget);

    horizontalLayout->addWidget(new LogsWidget(mFunctionsManager.getData()));
    verticalLayout->addLayout(horizontalLayout);
    dockControlButtons->setWidget(raspberryControlButtons);

    addDockWidget(Qt::BottomDockWidgetArea, dockControlButtons);
    disableCloseButton(dockControlButtons);

    auto *mainWidget = new QWidget;
    mainWidget->setLayout(verticalLayout);

    setCentralWidget(mainWidget);
}

void PiManagerWindow::disableCloseButton(QDockWidget *dockFunctionsWidget) const {
    dockFunctionsWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    //dockFunctionsWidget->setFeatures(QDockWidget::DockWidgetMovable | QDockWidget::DockWidgetFloatable);
    dockFunctionsWidget->setFeatures(0);
}
