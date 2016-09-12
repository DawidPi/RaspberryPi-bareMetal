//
// Created by Dawid on 12.09.2016.
//

#ifndef PIMANAGER_TREEWIDGET_H
#define PIMANAGER_TREEWIDGET_H

class QString;

class QTreeWidget;


class FunctionTreeWidgetWrapper {
    FunctionTreeWidgetWrapper(QTreeWidget &treeWidget);

    void appendFunction(const QString &functionName, const QString &returnValue, const QString &inputParameters);

};


#endif //PIMANAGER_TREEWIDGET_H
