//
// Created by Dawid on 27.09.2016.
//

#ifndef PIMANAGER_CONTROLBUTTONS_H
#define PIMANAGER_CONTROLBUTTONS_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>

//todo add documentation

class ControlButtons : public QWidget {
Q_OBJECT
public:
    ControlButtons();

    ControlButtons(const ControlButtons &rhs) = delete;

    ControlButtons(ControlButtons &&rhs) = delete;

    enum class States {
        NOT_CONNECTED, CONNECTED, RUNNING, FLASHING
    };

    void setNewStatus(States newState);

private:

    QPushButton *mConnectButton;
    QPushButton *mStartStopButton;
    QPushButton *mFlashButton;

    const QString mStartStopButtonText = "START";
    const QString mStopButtonText = "STOP";
    const QString mFlashButtonText = "FLASH";
    const QString mConnectButtonText = "CONNECT";
    const QString mDisconnectButtonText = "DISCONNECT";

    void setButtonsForConnected();
    void setButtonsForRunning();
    void setButtonsForFlashing();
    void setButtonsForNotConnected();
};


#endif //PIMANAGER_CONTROLBUTTONS_H
