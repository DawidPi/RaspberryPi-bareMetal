//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_FILEWIDGET_HPP
#define PIMANAGER_FILEWIDGET_HPP

#include <QtWidgets/QWidget>

class FileWidget : public QWidget {
Q_OBJECT
public:
    FileWidget(const QString &title, QWidget *parent = nullptr);

private:
    void setFileText(QLayout *layout);

    void setChooseFileButton(QLayout *layout);

    void setTitle(QLayout *layout, const QString &title);
};


#endif //PIMANAGER_FILEWIDGET_HPP
