//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_FILEWIDGET_HPP
#define PIMANAGER_FILEWIDGET_HPP

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>

/*!
 * Allows user for convenient choosing file from hard-drive
 */
class FileWidget : public QWidget {
Q_OBJECT
public:
    FileWidget(const FileWidget &rhs) = delete;

    FileWidget(const FileWidget &&rhs) = delete;

    /*!
     * Default Qt-like constructor
     *
     * @param parent default Qt-like argument for all QtWidgets' constructors
     */
    FileWidget(QWidget *parent = nullptr);

    /*!
     * allows for returning string, which represents a path to the file chosen by user
     * @return QString object, which represents path to the chosen file.
     */
    QString getFilePath() const;

    ~FileWidget() = default;
private:
    QLineEdit *mFilePathWidget;

    void setFileText(QLayout *layout);
    void setChooseFileButton(QLayout *layout);
};


#endif //PIMANAGER_FILEWIDGET_HPP
