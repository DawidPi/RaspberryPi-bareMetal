//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_SERIALPORTSCOMBOBOX_HPP
#define PIMANAGER_SERIALPORTSCOMBOBOX_HPP


#include <QtWidgets/QComboBox>
#include <QtCore/QTimer>
#include <QtSerialPort/QSerialPortInfo>

/*!
 * Represents comboBox with values of available serial ports available in PC
 */
class SerialPortsComboBox : public QComboBox {
Q_OBJECT
    const unsigned int updateIntervalMs = 500;
public:
    /*!
     * Default Qt-like constructor, which takes parent as an argument
     *
     * @param Qt-like parent pointer
     */
    SerialPortsComboBox(QWidget *parent = nullptr);

    /*!
     * Signal emitted, when Com port gets selected. Com port represented as int number
     */
    Q_SIGNAL void comPortSelected(int portNumber);

    /*!
     * Signal emitted, when Com port gets selected. Com port represented as string e.g. "COM0"
     */
    Q_SIGNAL void comPortSelected(const QString &portName);

    /*!
     * Slot for managing enable/disable flag for widget.
     */
    Q_SLOT void enable(bool enabled);

private:
    QVector<QString> mCurrentlyAvailablePorts;
    Q_SLOT void onItemSelected(int);

    //workaround for Win7, where there is no system
    //implementation of changes in ports
    Q_SLOT void updateComPorts();

    void createTimer();
    void connectSignals();
    void disconnectSignals();
};


#endif //PIMANAGER_SERIALPORTSCOMBOBOX_HPP
