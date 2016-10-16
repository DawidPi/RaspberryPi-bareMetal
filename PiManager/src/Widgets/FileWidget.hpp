//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_FILEWIDGET_HPP
#define PIMANAGER_FILEWIDGET_HPP

#include <QtWidgets/QWidget>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QAbstractButton>

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
     * @param extensions filter for file extension.
     *              Unfortunatelly for some reason does not work in current Qt
     * @param parent default Qt-like argument for all QtWidgets' constructors
     */
    FileWidget(const QString &extensions = QString(), QWidget *parent = nullptr);

    Q_SIGNAL void filePathChanged(const QString &newPath);

    /*!
     * allows for returning string, which represents a path to the file chosen by user
     * @return QString object, which represents path to the chosen file.
     */
    QString getFilePath() const;

    ~FileWidget() = default;
private:
    QLineEdit *mFilePathWidget;
    QAbstractButton *mFileChooseButton;
    QString mExtensions;

    Q_SLOT void chooseFileButtonPressed();

    Q_SLOT void internalFilePathChanged(const QString &);

    void setFileText(QLayout *layout);
    void setChooseFileButton(QLayout *layout);
};


#endif //PIMANAGER_FILEWIDGET_HPP
