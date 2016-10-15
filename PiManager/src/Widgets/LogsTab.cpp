//
// Created by Dawid on 15.10.2016.
//

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSplitter>
#include "LogsTab.hpp"
#include "FunctionsWidget.hpp"


LogsTab::LogsTab(const LogsWidget::FunctionLogsMap &logs, QWidget *parent) :
        QWidget(parent) {
    auto *functionsWidget = new FunctionsWidget;
    auto *logsWidget = new LogsWidget(logs);


    auto splitter = new QSplitter(this);
    splitter->addWidget(functionsWidget);
    splitter->addWidget(logsWidget);

    splitter->setOrientation(Qt::Horizontal);
    splitter->setSizes(QList<int>{200, logsWidget->size().width()});

    auto *layout = new QVBoxLayout(this);
    layout->addWidget(splitter);

    setLayout(layout);
}
