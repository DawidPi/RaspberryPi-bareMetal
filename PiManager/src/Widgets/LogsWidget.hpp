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
     * @param parent Qt parent pointer. Please refer to Qt documentation
     */
    LogsWidget(QWidget *parent = 0);

    LogsWidget(const LogsWidget &rhs) = delete;

    LogsWidget(LogsWidget &&rhs) = delete;

    /*!
     * Appends single string to function's logs.
     *
     * Class stores logs in map. Function automatically adds functionItem to the map
     * if this does not exist.
     *
     * @param functionItem WidgetItem pointer, that represents function
     * @param log QString type log, that is to be appended to functionLogs.
     */
    void appendLogToFunction(FunctionLogsMap::key_type functionItem,
                             const FunctionLogsMap::mapped_type::value_type &log);

    /*!
     * Appends list of logs of type QString to function's logs.
     *
     * Class stores logs in map. Function automatically adds functionItem to the map
     * if this does not exist.
     *
     * @param functionItem WidgetItem pointer, that represents function
     * @param logs QStringList type list of logs, that is to be appended to functionLogs.
     */
    void appendLogsToFunction(FunctionLogsMap::key_type functionItem,
                              const FunctionLogsMap::mapped_type &logs);

    /*!
     * Displays logs from a specified function
     *
     * @param functionItem QTreeWidgetItem, that represents function, of which
     *                      logs are to be displayed.
     */
    void displayLogsFromFunction(FunctionLogsMap::key_type functionItem);

private:
    FunctionLogsMap mMap;
    QTextEdit *mTextWidget;

    void setUpWidget();

    void registerFunction(FunctionLogsMap::key_type functionItem);

    bool functionNotAppended(QTreeWidgetItem *functionItem);

    void appendFunction(QTreeWidgetItem *functionItem);
};


#endif //PIMANAGER_LOGSWIDGET_HPP
