//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_SETTINGSTAB_HPP
#define PIMANAGER_SETTINGSTAB_HPP


#include <QtWidgets/QWidget>
#include <Common/SettingsManager.hpp>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QFormLayout>
#include "SerialPortsComboBox.hpp"

/*!
 * Widget, which contains all the settings needed for communiacting with RaspberryPi
 */
class SettingsTab : public QWidget {
Q_OBJECT
public:
    SettingsTab(const SettingsTab &rhs) = delete;

    SettingsTab(const SettingsTab &&rhs) = delete;

    /*!
     * default Qt-like constructor
     *
     * @param parent Qt-like parameter for widget.
     */
    SettingsTab(QWidget *parent = nullptr);

    /*!
     * Slot for managing clickability of widgets.
     */
    Q_SLOT void enable(bool enabled);

    ~SettingsTab() = default;

private:
    SettingsManager mPersonalSettingsValidator;
    QVBoxLayout *mLayout;
    QLineEdit *mErrorLine = nullptr;
    SerialPortsComboBox *mSerialPortComboBox;

    Q_SLOT void addr2LineChanged(const QString &newPath);

    Q_SLOT void executablePathChanged(const QString &newPath);

    Q_SLOT void serialPortNameChanged(const QString &newSerialPortName);

    Q_SLOT void fakeTimerSlot();

    Q_SLOT void settingsInvalid(const QString &member, const QString &reason);

    Q_SIGNAL void changeEnable(bool);

    void setUpWidget();

    void setUpValidator();

    void deleteErrorMessage();

    void setUpErrorStyleSheet();
};


#endif //PIMANAGER_SETTINGSTAB_HPP
