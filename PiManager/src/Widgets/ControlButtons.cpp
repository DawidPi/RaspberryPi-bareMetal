//
// Created by Dawid on 27.09.2016.
//

#include <QtWidgets/QPushButton>
#include "ControlButtons.h"

ControlButtons::ControlButtons() {
    setNewStatus(States::NOT_CONNECTED);

    mButtons.addButton(new QPushButton(""));
    mButtons.addButton(new QPushButton(mFlashButtonText));
    mButtons.addButton(new QPushButton(""));

    setNewStatus(States::NOT_CONNECTED);
}

void ControlButtons::setNewStatus(ControlButtons::States newState) {
    clearAllButtons();

    switch (newState) {
        case States::CONNECTED:
            setButtonsForConnected();
            break;
        case States::RUNNING:
            setButtonsForRunning();
            break;
        case States::FLASHING:
            setButtonsForFlashing();
            break;
        case States::NOT_CONNECTED:
            setButtonsForNotConnected();
            break;
    }

}

void ControlButtons::clearAllButtons() {
    for (auto buttonPtr : mButtons.buttons()) {
        mButtons.removeButton(buttonPtr);
    }
}

void ControlButtons::setButtonsForConnected() {
    getConnectButton().setCheckable(true);
    getConnectButton().setText(mDisconnectButtonText);

    getFlashButton().setCheckable(true);
    getStartButton().setText(mStartButtonText);
    getStartButton().setCheckable(true);
}

void ControlButtons::setButtonsForRunning() {
    getConnectButton().setCheckable(false);
    getConnectButton().setText(mDisconnectButtonText);
    getFlashButton().setCheckable(false);

    getStartButton().setCheckable(true);
    getStartButton().setText(mStopButtonText);
}

void ControlButtons::setButtonsForFlashing() {
    getConnectButton().setCheckable(false);
    getConnectButton().setText(mDisconnectButtonText);

    getFlashButton().setCheckable(false);
    getStartButton().setCheckable(false);
}

void ControlButtons::setButtonsForNotConnected() {
    getConnectButton().setCheckable(true);
    getConnectButton().setText(mConnectButtonText);

    getFlashButton().setCheckable(false);

    getStartButton().setCheckable(false);
    getStartButton().setText(mStartButtonText);
}


QAbstractButton &ControlButtons::getConnectButton() {
    return *(mButtons.button(static_cast<int>(Buttons::CONNECT)));
}

QAbstractButton &ControlButtons::getFlashButton() {
    return *(mButtons.button(static_cast<int>(Buttons::FLASH)));
}

QAbstractButton &ControlButtons::getStartButton() {
    return *(mButtons.button(static_cast<int>(Buttons::STOP_START)));
}
