//
// Created by Dawid on 05.10.2016.
//

#include "FunctionsTreeManager.hpp"

void FunctionsTreeManager::registerFunction(QTreeWidgetItem *functionItem) {
    if (functionNotAppended(functionItem))
        appendFunction(functionItem);

    Q_EMIT logsUpdated();
}

void FunctionsTreeManager::appendFunction(QTreeWidgetItem *functionItem) {
    mMap.insert(functionItem, QStringList());
}

bool FunctionsTreeManager::functionNotAppended(QTreeWidgetItem *functionItem) {
    return mMap.find(functionItem) == mMap.end();
}

void FunctionsTreeManager::appendLogToFunction(QTreeWidgetItem *functionItem, const QString &log) {
    registerFunction(functionItem);
    mMap[functionItem].append(log);
    Q_EMIT logsUpdated();
}

void FunctionsTreeManager::appendLogsToFunction(QTreeWidgetItem *functionItem, const QStringList &logs) {
    registerFunction(functionItem);
    mMap[functionItem].append(logs);
    Q_EMIT logsUpdated();
}

const FunctionsTreeManager::FunctionLogsMap &FunctionsTreeManager::getData() const {
    return mMap;
}