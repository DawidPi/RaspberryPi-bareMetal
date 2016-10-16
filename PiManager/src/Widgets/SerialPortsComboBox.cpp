//
// Created by Dawid on 15.10.2016.
//

#include "SerialPortsComboBox.hpp"

SerialPortsComboBox::SerialPortsComboBox(QWidget *parent) : QComboBox(parent) {
    connectSignals();
    createTimer();
    updateComPorts();
    if (mCurrentlyAvailablePorts.size())
        setCurrentIndex(0);
}

void SerialPortsComboBox::createTimer() {
    auto *portsRefreshTimer = new QTimer(this);

    portsRefreshTimer->setTimerType(Qt::CoarseTimer);
    portsRefreshTimer->setInterval(updateIntervalMs);
    connect(portsRefreshTimer, SIGNAL(timeout()), this, SLOT(updateComPorts()));
}

void SerialPortsComboBox::updateComPorts() {
    clear();
    mCurrentlyAvailablePorts.clear();

    if (QSerialPortInfo::availablePorts().size() == 0) {
        disconnectSignals();
        return;
    }

    connectSignals();
    for (auto &port : QSerialPortInfo::availablePorts()) {
        addItem(port.portName());
        mCurrentlyAvailablePorts.append(port.portName());
    }
}

void SerialPortsComboBox::connectSignals() {
    connect(this, SIGNAL(activated(int)), this, SLOT(onItemSelected(int)));
    connect(this, SIGNAL(activated(int)), this, SLOT(onItemSelected(int)));
}

void SerialPortsComboBox::onItemSelected(int portNum) {
    Q_EMIT(comPortSelected(portNum));
    Q_EMIT(comPortSelected(mCurrentlyAvailablePorts.at(portNum)));
}

void SerialPortsComboBox::disconnectSignals() {
    disconnect(this, SIGNAL(activated(int)), this, SLOT(onItemSelected(int)));
    disconnect(this, SIGNAL(activated(int)), this, SLOT(onItemSelected(int)));
}

void SerialPortsComboBox::enable(bool enabled) {
    setEnabled(enabled);
}

QString SerialPortsComboBox::getChosenSerialPort() {
    return currentText();
}
