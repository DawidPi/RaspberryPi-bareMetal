//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_SERIALPORTSCOMBOBOX_HPP
#define PIMANAGER_SERIALPORTSCOMBOBOX_HPP


#include <QtWidgets/QComboBox>
#include <QtCore/QTimer>

class SerialPortsComboBox : public QWidget {
Q_OBJECT
    const unsigned int updateIntervalMs = 500;
public:
    SerialPortsComboBox(QWidget *parent = nullptr);

    Q_SIGNAL void comPortSelected(int portNumber);

    Q_SIGNAL void comPortSelected(const QString &portName);

private:
    QComboBox *mComboBox;
    QVector<QString> mCurrentlyAvailablePorts;
    Q_SLOT void onItemSelected(int);

    //workaround for Win7, where there is no system
    //implementation of changes in ports
    Q_SLOT void updateComPorts();

    void createTimer();

    void setUpWidget();
};


#endif //PIMANAGER_SERIALPORTSCOMBOBOX_HPP
