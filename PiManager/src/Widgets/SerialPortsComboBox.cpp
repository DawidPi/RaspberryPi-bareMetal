//
// Created by Dawid on 15.10.2016.
//

#include "SerialPortsComboBox.hpp"
#include <QtSerialPort/QSerialPortInfo>

SerialPortsComboBox::SerialPortsComboBox(QWidget *parent) : QComboBox(parent) {
    setUpWidget();
    createTimer();
    updateComPorts();
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
    for (auto &port : QSerialPortInfo::availablePorts()) {
        addItem(port.portName());
        mCurrentlyAvailablePorts.append(port.portName());
    }
}

void SerialPortsComboBox::setUpWidget() {
    connect(this, SIGNAL(activated(int)), this, SLOT(onItemSelected(int)));
}

void SerialPortsComboBox::onItemSelected(int portNum) {
    Q_EMIT(comPortSelected(portNum));
    Q_EMIT(comPortSelected(mCurrentlyAvailablePorts.at(portNum)));
}
