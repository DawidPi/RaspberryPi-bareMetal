//
// Created by Dawid on 16.10.2016.
//

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QtCore/QFile>
#include <QtCore/QFileInfo>
#include "SettingsManager.hpp"

bool SettingsManager::validateSettings() const {
    return validatePortName() and validateExecutablePath() and validateAddr2LinePath();

}

bool SettingsManager::validatePortName() const {
    if (mSerialPortName.isEmpty()) {
        Q_EMIT settingsInvalid(mSerialPortMemberName, mSerialPortEmpty);
        return false;
    }

    QSerialPort serialPort(mSerialPortName);
    if (!serialPort.open(QIODevice::ReadWrite)) {
        Q_EMIT settingsInvalid(mSerialPortMemberName, mSerialPortBusy);
        return false;
    }
    serialPort.close();

    return true;
}

bool SettingsManager::validateExecutablePath() const {
    if (mRaspberryExecutableMemberName.isEmpty()) {
        Q_EMIT settingsInvalid(mRaspberryExecutableMemberName, mStringEmptyReason);
        return false;
    }

    QFileInfo file(mExecutablePath);

    if (!file.exists()) {
        Q_EMIT settingsInvalid(mRaspberryExecutableMemberName, mFileDoesntExist);
        return false;
    }

    if (file.isReadable()) {
        Q_EMIT settingsInvalid(mRaspberryExecutableMemberName, mMissingPermissions);
        return false;
    }

    return true;
}

bool SettingsManager::validateAddr2LinePath() const {
    if (mAddr2LinePath.isEmpty()) {
        Q_EMIT settingsInvalid(mAddr2LinePathMemberName, mStringEmptyReason);
        return false;
    }

    QFileInfo file(mAddr2LinePath);

    if (!file.exists()) {
        Q_EMIT settingsInvalid(mAddr2LinePathMemberName, mFileDoesntExist);
        return false;
    }

    if (!file.isExecutable()) {
        Q_EMIT settingsInvalid(mAddr2LinePathMemberName, mMissingPermissions);
        return false;
    }

    return true;
}

const QString &SettingsManager::getSerialPortName() const {
    return mSerialPortName;
}

const QString &SettingsManager::getAddr2LinePath() const {
    return mAddr2LinePath;
}

const QString &SettingsManager::getExecutablePath() const {
    return mExecutablePath;
}

void SettingsManager::setSerialPort(const QString &portName) {
    mSerialPortName = portName;
}

void SettingsManager::setRaspberryPiExecutablePath(const QString &path) {
    mExecutablePath = path;
}

void SettingsManager::setAddr2linePath(const QString &path) {
    mAddr2LinePath = path;
}
