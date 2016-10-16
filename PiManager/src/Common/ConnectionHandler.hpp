//
// Created by Dawid on 16.10.2016.
//

#ifndef PIMANAGER_CONNECTIONHANDLER_HPP
#define PIMANAGER_CONNECTIONHANDLER_HPP


#include <QtCore/QObject>

class ConnectionHandler : public QObject {
Q_OBJECT
public:
    /*!
     * Default constructor
     */
    ConnectionHandler();

    Q_SLOT void startConnection(const QString &portName);

    Q_SLOT void stopConnection(const QString &portName);

    Q_SIGNAL void connectionSuccessful();

    Q_SIGNAL void connectionFailed();

    Q_SIGNAL void connectionTimeout();

};


#endif //PIMANAGER_CONNECTIONHANDLER_HPP
