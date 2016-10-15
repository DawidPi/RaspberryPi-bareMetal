//
// Created by Dawid on 27.09.2016.
//

#include <QtWidgets/QPushButton>
#include <QtWidgets/QBoxLayout>
#include "ControlButtons.hpp"

ControlButtons::ControlButtons(QWidget *parent) : QWidget(parent) {
    mStartStopButton = (new QPushButton(mStartStopButtonText));
    mConnectButton = (new QPushButton(mConnectButtonText));
    mFlashButton = (new QPushButton(mFlashButtonText));

    auto *horizontalBoxLayout = new QBoxLayout(QBoxLayout::LeftToRight);

    horizontalBoxLayout->addWidget(mConnectButton);
    horizontalBoxLayout->addWidget(mStartStopButton);
    horizontalBoxLayout->addWidget(mFlashButton);

    setLayout(horizontalBoxLayout);

    setNewStatus(States::NOT_CONNECTED);
}

void ControlButtons::setNewStatus(ControlButtons::States newState) {

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

void ControlButtons::setButtonsForConnected() {
    mConnectButton->setEnabled(true);
    mConnectButton->setText(mDisconnectButtonText);

    mFlashButton->setEnabled(true);
    mStartStopButton->setText(mStartStopButtonText);
    mStartStopButton->setEnabled(true);
}

void ControlButtons::setButtonsForRunning() {
    mConnectButton->setEnabled(false);
    mConnectButton->setText(mDisconnectButtonText);
    mFlashButton->setEnabled(false);

    mStartStopButton->setEnabled(true);
    mStartStopButton->setText(mStopButtonText);
}

void ControlButtons::setButtonsForFlashing() {
    mConnectButton->setEnabled(false);
    mConnectButton->setText(mDisconnectButtonText);

    mFlashButton->setEnabled(false);
    mStartStopButton->setEnabled(false);
}

void ControlButtons::setButtonsForNotConnected() {
    mConnectButton->setEnabled(true);
    mConnectButton->setText(mConnectButtonText);

    mFlashButton->setEnabled(false);

    mStartStopButton->setEnabled(false);
    mStartStopButton->setText(mStartStopButtonText);
}
