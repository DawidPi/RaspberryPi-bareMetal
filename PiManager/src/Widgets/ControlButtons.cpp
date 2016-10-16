//
// Created by Dawid on 27.09.2016.
//

#include <QtWidgets/QPushButton>
#include <QtWidgets/QBoxLayout>
#include <QtWidgets/QMessageBox>
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

    mCurrentState = newState;

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

void ControlButtons::internalConnectPressed() {
    Q_EMIT connectButtonPressed();
}

void ControlButtons::internalFlashPressed() {
    Q_EMIT flashButtonPressed();
}

void ControlButtons::internalStartStopPressed() {
    if (mCurrentState == States::RUNNING)
            Q_EMIT stopButtonPressed();
    else
            Q_EMIT startButtonPressed();
}

void ControlButtons::connectionLost() {
    if (mCurrentState == States::FLASHING) {
        flashingFinished(false);
        return;
    }

    QMessageBox warningMsg;
    warningMsg.setWindowTitle("Connection failed");
    warningMsg.setText("Connection with RaspberryPi failed!");
    warningMsg.setDetailedText(
            "There is wrong serial connection selected to it or no apropriate bootlaoder is installed.");
    warningMsg.setIcon(QMessageBox::Information);
    warningMsg.setStandardButtons(QMessageBox::Ok);
    warningMsg.exec();

    setNewStatus(States::NOT_CONNECTED);
}

void ControlButtons::commandFailed() {
    QMessageBox warningMsg;
    warningMsg.setWindowTitle("Communication failed");
    warningMsg.setText("Some command was not answered by Raspberry Pi");
    warningMsg.setDetailedText("Connection to the Raspberry Pi was lost.");
    warningMsg.setIcon(QMessageBox::Information);
    warningMsg.setStandardButtons(QMessageBox::Ok);
    warningMsg.exec();

    setNewStatus(States::NOT_CONNECTED);
}

void ControlButtons::flashingFinished(bool successful) {

    if (!successful) {
        QMessageBox warningMsg;
        warningMsg.setWindowTitle("Flashing failed");
        warningMsg.setText("Flashing failed. Please try again.");
        warningMsg.setDetailedText("Flashing failed. Probably connection was lost. Please try again!");
        warningMsg.setIcon(QMessageBox::Information);
        warningMsg.setStandardButtons(QMessageBox::Ok);
        warningMsg.exec();
    }

    setNewStatus(States::CONNECTED);
}
