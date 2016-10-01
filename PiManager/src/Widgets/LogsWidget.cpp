//
// Created by Dawid on 01.10.2016.
//

#include <QtWidgets/QVBoxLayout>
#include "LogsWidget.hpp"

LogsWidget::LogsWidget(QWidget *parent) :
        QWidget(parent) {
    setUpWidget();
}

void LogsWidget::setUpWidget() {
    auto *layout = new QVBoxLayout;
    mTextWidget = new QTextEdit;
    mTextWidget->setReadOnly(true);
    layout->addWidget(mTextWidget);

    setLayout(layout);
}

void LogsWidget::registerFunction(QTreeWidgetItem *functionItem) {
    if (functionNotAppended(functionItem))
        appendFunction(functionItem);
}

void LogsWidget::appendFunction(QTreeWidgetItem *functionItem) {
    mMap.insert(functionItem, QStringList());
}

bool LogsWidget::functionNotAppended(QTreeWidgetItem *functionItem) {
    return mMap.find(functionItem) == mMap.end();
}

void LogsWidget::appendLogToFunction(QTreeWidgetItem *functionItem, const QString &log) {
    registerFunction(functionItem);
    mMap[functionItem].append(log);
}

void LogsWidget::appendLogsToFunction(QTreeWidgetItem *functionItem, const QStringList &logs) {
    registerFunction(functionItem);
    mMap[functionItem].append(logs);
}

void LogsWidget::displayLogsFromFunction(QTreeWidgetItem *functionItem) {
    mTextWidget->clear();
    for (const auto &string : mMap[functionItem]) {
        mTextWidget->append(string);
        mTextWidget->append("\n");
    }
}
