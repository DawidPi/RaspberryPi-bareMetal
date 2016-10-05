//
// Created by Dawid on 05.10.2016.
//

#ifndef PIMANAGER_FUNCTIONSTREEMANAGER_HPP
#define PIMANAGER_FUNCTIONSTREEMANAGER_HPP

#include <QMap>
#include <QTreeWidgetItem>
#include <QStringList>

class FunctionsTreeManager : QObject {
Q_OBJECT
public:
    typedef QMap<QTreeWidgetItem *, QStringList> FunctionLogsMap;

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
     *  Gets the result of all the class's job.
     *
     * @return underlying data of type FunctionLogsMap (QMap<QTreeWidgetItem *, QStringList>)
     */
    const FunctionLogsMap &getData() const;


Q_SIGNALS:

    void logsUpdated();

private:
    FunctionLogsMap mMap;

    bool functionNotAppended(QTreeWidgetItem *functionItem);

    void appendFunction(QTreeWidgetItem *functionItem);

    void registerFunction(FunctionLogsMap::key_type functionItem);
};


#endif //PIMANAGER_FUNCTIONSTREEMANAGER_HPP
