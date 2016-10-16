//
// Created by Dawid on 01.10.2016.
//

#ifndef PIMANAGER_LOGSWIDGET_HPP
#define PIMANAGER_LOGSWIDGET_HPP


#include <QtWidgets/QWidget>
#include <QtWidgets/QTreeWidgetItem>
#include <QtWidgets/QTextEdit>

/*!
 * Widget, for showing logs from a specific function
 */
class LogsWidget : public QWidget {
Q_OBJECT
public:
    typedef QMap<QTreeWidgetItem *, QStringList> FunctionLogsMap;

    /*!
     *  Constructor for this widget
     * @param functionsLog reference to the container on logs
     * @param parent Qt parent pointer. Please refer to Qt documentation
     */
    LogsWidget(const FunctionLogsMap &functionsLog, QWidget *parent = 0);

    LogsWidget(const LogsWidget &rhs) = delete;

    LogsWidget(LogsWidget &&rhs) = delete;

    /*!
     * Displays logs from a specified function
     *
     * @param functionItem QTreeWidgetItem, that represents function, of which
     *                      logs are to be displayed.
     */
    void displayLogsFromFunction(FunctionLogsMap::key_type functionItem);

private:
    const FunctionLogsMap &mMap;
    QTextEdit *mTextWidget;

    void setUpWidget();
};


#endif //PIMANAGER_LOGSWIDGET_HPP
