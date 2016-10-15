//
// Created by Dawid on 01.10.2016.
//

#include <QtWidgets/QVBoxLayout>
#include "LogsWidget.hpp"

LogsWidget::LogsWidget(const FunctionLogsMap &functionsLog, QWidget *parent) :
        QWidget(parent), mMap(functionsLog) {
    setUpWidget();
}

void LogsWidget::setUpWidget() {
    auto *layout = new QVBoxLayout;
    mTextWidget = new QTextEdit;
    mTextWidget->setReadOnly(true);
    layout->addWidget(mTextWidget);

    setLayout(layout);
}

void LogsWidget::displayLogsFromFunction(QTreeWidgetItem *functionItem) {
    mTextWidget->clear();
    for (const auto &string : mMap[functionItem]) {
        mTextWidget->append(string);
        mTextWidget->append("\n");
    }
}
