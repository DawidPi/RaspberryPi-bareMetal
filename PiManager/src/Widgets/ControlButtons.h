//
// Created by Dawid on 27.09.2016.
//

#ifndef PIMANAGER_CONTROLBUTTONS_H
#define PIMANAGER_CONTROLBUTTONS_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QButtonGroup>

//todo add documentation

class ControlButtons : public QWidget {
Q_OBJECT
public:
    ControlButtons();

    enum class Buttons {
        STOP_START, FLASH, CONNECT
    };
    enum class States {
        NOT_CONNECTED, CONNECTED, RUNNING, FLASHING
    };

    void setNewStatus(States newState);

private:
    void clearAllButtons();

    //todo check if it automatically handles freeing resources
    QButtonGroup mButtons;

    const QString mStartButtonText = "START";
    const QString mStopButtonText = "STOP";
    const QString mFlashButtonText = "FLASH";
    const QString mConnectButtonText = "CONNECT";
    const QString mDisconnectButtonText = "DISCONNECT";

    void setButtonsForConnected();

    void setButtonsForRunning();

    void setButtonsForFlashing();

    void setButtonsForNotConnected();

    QAbstractButton &getConnectButton();

    QAbstractButton &getFlashButton();

    QAbstractButton &getStartButton();
};


#endif //PIMANAGER_CONTROLBUTTONS_H
