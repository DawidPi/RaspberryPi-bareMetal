//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_LOGSTAB_HPP
#define PIMANAGER_LOGSTAB_HPP


#include <QtWidgets/QWidget>
#include "LogsWidget.hpp"

class LogsTab : public QWidget {
public:
    LogsTab(const LogsWidget::FunctionLogsMap &logs, QWidget *parent = 0);
};


#endif //PIMANAGER_LOGSTAB_HPP
