//
// Created by Dawid on 30.09.2016.
//

#ifndef PIMANAGER_FUNCTIONSWIDGET_HPP
#define PIMANAGER_FUNCTIONSWIDGET_HPP


#include <QtWidgets/QWidget>
#include <QtWidgets/QTreeWidget>

/*!
 *  Widget, that represents functionCalls in order they were executed
 *  in form of a tree
 */
class FunctionsWidget : public QWidget {
public:
    /*!
     * typedef for a Pair of Strings. First string represents returning value type of function and second
     * string represents function name (and optionally it's arguments)
     */
    typedef QPair<QString, QString> FunctionName;

    /*!
     * Constructor
     * @param Qt style parent (see documentation of QWidget)
     */
    FunctionsWidget(QWidget *parent);

    FunctionsWidget(const FunctionsWidget &rhs) = delete;

    FunctionsWidget(FunctionsWidget &&rhs) = delete;

    /*!
     * Adds most top level function call to the tree. In embedded computing it represents new
     * iteration of mainloop.
     *
     * Method must be called at least once before other methods
     */
    void newMainLoop();

    /*!
     * Adds new function to the tree in the same branch as previous function call.
     *
     * In the tree it will be seen as:
     *     - mainLoop()
     *         - previousFunctionCall()
     *         - functionName()
     *
     * @param functionName pair of string which represents function (see @ref FunctionName)
     */
    void newFunctionCall(const FunctionName &functionName);

    /*!
     * Adds new function to the tree in the sub branch of previous function call
     *
     * In the tree it will be seen as:
     *     - mainLoop()
     *         - previousFunctionCall()
     *         - functionName
     *
     * @param functionName  pair of string which represents function (see @ref FunctionName)
     */
    void newSubFunctionCall(const FunctionName &functionName);

    /*!
     * Returns to the parent branch of the tree. Should be called when function added to stack finishes.
     */
    void functionReturn();

private:
    const QString mHeaderText = "Functions: ";

    QTreeWidget *mTreeWidget;
    QTreeWidgetItem *mLastItem;

    //helper functions
    void initializeMembers();

    void widgetSetUp();

    void assertLastItemValid();

    void assertParentHasChildren();

    void assertLastItemHasParent();
};


#endif //PIMANAGER_FUNCTIONSWIDGET_HPP
