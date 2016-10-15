//
// Created by Dawid on 27.09.2016.
//



#include <QtWidgets/QVBoxLayout>
#include "PiManagerWindow.hpp"
#include "LogsWidget.hpp"
#include "LogsTab.hpp"
#include "SerialPortsComboBox.hpp"
#include "SettingsTab.hpp"
#include <QtWidgets/QDockWidget>

PiManagerWindow::PiManagerWindow() {
    auto *mFunctionsView = new FunctionsWidget(0);
    auto *raspberryControlButtons = new ControlButtons(0);

    setUpWidget(mFunctionsView, raspberryControlButtons);
}

void PiManagerWindow::setUpWidget(FunctionsWidget *mFunctionsView, ControlButtons *raspberryControlButtons) {
    auto *dockControlButtons = new QDockWidget;
    auto *tabWidget = new QTabWidget;

    tabWidget->addTab(new LogsTab(mFunctionsManager.getData()), "Logs");
    tabWidget->addTab(new SettingsTab, "Settings");

    setCentralWidget(tabWidget);
    dockControlButtons->setWidget(raspberryControlButtons);

    addDockWidget(Qt::BottomDockWidgetArea, dockControlButtons);
    disableCloseButton(dockControlButtons);
}

void PiManagerWindow::disableCloseButton(QDockWidget *dockFunctionsWidget) const {
    dockFunctionsWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dockFunctionsWidget->setFeatures(0);
}
