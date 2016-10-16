//
// Created by Dawid on 27.09.2016.
//

#ifndef PIMANAGER_PIMANAGERWINDOW_H
#define PIMANAGER_PIMANAGERWINDOW_H

#include <QMainWindow>
#include <Common/FunctionsTreeManager.hpp>
#include "ControlButtons.hpp"
#include "FunctionsWidget.hpp"

/*!
 * Represents Application's main window, which contains logs and settings for RaspberryPi communication
 */
class PiManagerWindow : public QMainWindow {
Q_OBJECT
public:
    PiManagerWindow(const PiManagerWindow &rhs) = delete;

    PiManagerWindow(const PiManagerWindow &&rhs) = delete;

    /*!
     * Default constructor
     */
    PiManagerWindow();


private:
    FunctionsTreeManager mFunctionsManager;
    void setUpWidget(FunctionsWidget *mFunctionsView, ControlButtons *raspberryControlButtons);

    void disableCloseButton(QDockWidget *dockFunctionsWidget) const;
};


#endif //PIMANAGER_PIMANAGERWINDOW_H
