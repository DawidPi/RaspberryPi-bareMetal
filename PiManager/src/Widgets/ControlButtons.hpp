//
// Created by Dawid on 27.09.2016.
//

#ifndef PIMANAGER_CONTROLBUTTONS_H
#define PIMANAGER_CONTROLBUTTONS_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>


/*!
 *  \brief Widget with 3 buttons horizontally aligned.
 *  Buttons are responsible for managing RaspberryPi
 *  activities.
 *
 *  Buttons are responsible for invoking actions like
 *  start/stop program, connect to raspberryPi or
 *  flash new program to RaspberryPi
 */
class ControlButtons : public QWidget {
Q_OBJECT
public:
    ControlButtons(const ControlButtons &rhs) = delete;
    ControlButtons(ControlButtons &&rhs) = delete;

    /*!
     * The only constructor available.
     *
     * @param parent parent widget (as all QWidgets have please refer to Qt documentation)
     */
    ControlButtons(QWidget *parent = nullptr);

    /*!
     * Enum represents states of the program, which are possible (in terms of RaspberryPi activities)
     */
    enum class States {
        NOT_CONNECTED, /*! < RaspberryPi is not yet connected */
        CONNECTED, /*! < RaspberryPi connected, but neither flashing nor program is currently running */
        RUNNING, /*! < RaspberryPi's flashed program is running */
        FLASHING /*! < RaspberryPi's flashing program is currently running */
    };

    /*!
     * Sets state of the program. This makes buttons greyed-out properly and
     * allows for text on buttons be set correctly.
     *
     * @param newState new State of the RaspberryPi management
     */
    void setNewStatus(States newState);

    virtual ~ControlButtons() {};


    /*!
     * SIGNAL on start Button pressed
     */
    Q_SIGNAL void startButtonPressed();

    /*!
     * SIGNAL on stop Button pressed
     */
    Q_SIGNAL void stopButtonPressed();

    /*!
     * SIGNAL on flash Button pressed
     */
    Q_SIGNAL void flashButtonPressed();

    /*!
     * SIGNAL on connect Button pressed
     */
    Q_SIGNAL void connectButtonPressed();


    Q_SLOT void connectionLost();

    Q_SLOT void commandFailed();

    Q_SLOT void flashingFinished(bool successful);

private:

    States mCurrentState;

    Q_SLOT void internalConnectPressed();

    Q_SLOT void internalFlashPressed();

    Q_SLOT void internalStartStopPressed();

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
