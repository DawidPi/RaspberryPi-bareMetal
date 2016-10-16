//
// Created by Dawid on 16.10.2016.
//

#ifndef PIMANAGER_SETTINGSMANAGER_HPP
#define PIMANAGER_SETTINGSMANAGER_HPP


#include <QtCore/QObject>
#include <QtSerialPort/QSerialPortInfo>

class SettingsManager : QObject {
Q_OBJECT
public:
    bool validateSettings() const;

    const QString &getSerialPortName() const;

    const QString &getAddr2LinePath() const;

    const QString &getExecutablePath() const;

    bool validatePortName() const;

    bool validateExecutablePath() const;

    bool validateAddr2LinePath() const;

    Q_SIGNAL void settingsInvalid(const QString &invalidMember, const QString &reason) const;

    Q_SLOT void setSerialPort(const QString &portName);

    Q_SLOT void setRaspberryPiExecutablePath(const QString &path);

    Q_SLOT void setAddr2linePath(const QString &path);

private:
    QString mSerialPortName;
    QString mExecutablePath;
    QString mAddr2LinePath;

    const QString mSerialPortMemberName = "Serial Port";
    const QString mRaspberryExecutableMemberName = "Raspberry Pi executable";
    const QString mAddr2LinePathMemberName = "Addr2Line filePath";

    const QString mStringEmptyReason = "Path empty";
    const QString mFileDoesntExist = "File does not exists";
    const QString mMissingPermissions = "Insufficient permissions";

    const QString mSerialPortBusy = "Cannot open Serial Port";
    const QString mSerialPortEmpty = "Empty Serial Port selected";

    const unsigned int mCommSpeed = 0;
};


#endif //PIMANAGER_SETTINGSMANAGER_HPP
