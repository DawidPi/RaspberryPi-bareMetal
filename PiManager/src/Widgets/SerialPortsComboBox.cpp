//
// Created by Dawid on 15.10.2016.
//

#include "SerialPortsComboBox.hpp"
#include <QtSerialPort/QSerialPortInfo>

SerialPortsComboBox::SerialPortsComboBox(QWidget *parent) : QWidget(parent) {
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
    mComboBox->clear();
    mCurrentlyAvailablePorts.clear();
    for (auto &port : QSerialPortInfo::availablePorts()) {
        mComboBox->addItem(port.portName());
        mCurrentlyAvailablePorts.append(port.portName());
    }
}

void SerialPortsComboBox::setUpWidget() {
    mComboBox = new QComboBox(this);
    connect(mComboBox, SIGNAL(activated(int)), this, SLOT(onItemSelected(int)));
}

void SerialPortsComboBox::onItemSelected(int portNum) {
    Q_EMIT(comPortSelected(portNum));
    Q_EMIT(comPortSelected(mCurrentlyAvailablePorts.at(portNum)));
}
