//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QHBoxLayout>
#include "LogsTab.hpp"
#include "FunctionsWidget.hpp"


LogsTab::LogsTab(const LogsWidget::FunctionLogsMap &logs, QWidget *parent) :
        QWidget(parent) {
    auto *functionsWidget = new FunctionsWidget;
    auto *logsWidget = new LogsWidget(logs);

    auto layout = new QHBoxLayout(this);
    layout->addWidget(functionsWidget);
    layout->addWidget(logsWidget);
}
