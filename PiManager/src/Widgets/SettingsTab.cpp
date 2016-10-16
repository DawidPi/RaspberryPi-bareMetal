//
// Created by Dawid on 15.10.2016.
//

#include "SettingsTab.hpp"
#include "FileWidget.hpp"

SettingsTab::SettingsTab(QWidget *parent) : QWidget(parent),
                                            mLayout(new QVBoxLayout(this)),
                                            mSerialPortComboBox(new SerialPortsComboBox) {
    setUpWidget();
    setUpValidator();
}

void SettingsTab::setUpWidget() {

    auto *raspberryBinaryFile = new FileWidget("RPI binary (*.hex)");
    auto *addr2LineFilePath = new FileWidget("Executable (*.exe)");

    auto *formLayout = new QFormLayout;
    formLayout->setVerticalSpacing(2 * formLayout->verticalSpacing());
    formLayout->setMargin(2 * formLayout->margin());
    formLayout->addRow("Binary file: ", raspberryBinaryFile);
    formLayout->addRow("Translator exe: ", addr2LineFilePath);
    formLayout->addRow("PC Port: ", mSerialPortComboBox);

    mLayout->addLayout(formLayout);

    connect(raspberryBinaryFile, SIGNAL(filePathChanged(
                                                const QString&)), this,
            SLOT(executablePathChanged(
                         const QString&)));
    connect(addr2LineFilePath, SIGNAL(filePathChanged(
                                              const QString&)), this,
            SLOT(addr2LineChanged(
                         const QString&)));
    connect(mSerialPortComboBox, SIGNAL(comPortSelected(
                                                const QString &)), this,
            SLOT(serialPortNameChanged(
                         const QString&)));

    QTimer::singleShot(500, this, SLOT(fakeTimerSlot()));
}

void SettingsTab::enable(bool enabled) {
    Q_EMIT changeEnable(enabled);
}

void SettingsTab::setUpValidator() {
    connect(&mPersonalSettingsValidator, SIGNAL(settingsInvalid(
                                                        const QString&, const QString&)),
            this, SLOT(settingsInvalid(
                               const QString&, const QString&)));
}

void SettingsTab::addr2LineChanged(const QString &newPath) {
    deleteErrorMessage();
    mPersonalSettingsValidator.setAddr2linePath(newPath);
    mPersonalSettingsValidator.validateSettings();
}


void SettingsTab::executablePathChanged(const QString &newPath) {
    deleteErrorMessage();
    mPersonalSettingsValidator.setRaspberryPiExecutablePath(newPath);
    mPersonalSettingsValidator.validateSettings();
}

void SettingsTab::serialPortNameChanged(const QString &newSerialPortName) {
    deleteErrorMessage();
    mPersonalSettingsValidator.setSerialPort(newSerialPortName);
    mPersonalSettingsValidator.validateSettings();
}

void SettingsTab::settingsInvalid(const QString &member, const QString &reason) {
    deleteErrorMessage();
    mErrorLine = new QLineEdit("ERROR: " + member + " is invalid, because : " + reason);
    mErrorLine->setStyleSheet("color: #FF0000; border: none");
    mLayout->addWidget(mErrorLine);
}

void SettingsTab::deleteErrorMessage() {
    if (mErrorLine)
        mErrorLine->deleteLater();

    mErrorLine = nullptr;
}

void SettingsTab::fakeTimerSlot() {
    mPersonalSettingsValidator.setSerialPort(mSerialPortComboBox->getChosenSerialPort());
    mPersonalSettingsValidator.validateSettings();
}

