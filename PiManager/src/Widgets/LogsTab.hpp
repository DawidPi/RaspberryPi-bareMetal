//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_LOGSTAB_HPP
#define PIMANAGER_LOGSTAB_HPP


#include <QtWidgets/QWidget>
#include "LogsWidget.hpp"

/*!
 * Represents Widget with logs
 */
class LogsTab : public QWidget {
public:
    LogsTab(const LogsTab &rhs) = delete;

    LogsTab(const LogsTab &&rhs) = delete;

    /*!
     * Default Qt-like constructor
     * @param logs reference to map, which containts functionItem -> logs maps.
     * @param parent Qt-like pointer to parent argument
     */
    LogsTab(const LogsWidget::FunctionLogsMap &logs, QWidget *parent = nullptr);

    ~LogsTab() = default;
};


#endif //PIMANAGER_LOGSTAB_HPP
