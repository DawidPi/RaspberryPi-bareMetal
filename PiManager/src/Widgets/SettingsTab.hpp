//
// Created by Dawid on 15.10.2016.
//

#ifndef PIMANAGER_SETTINGSTAB_HPP
#define PIMANAGER_SETTINGSTAB_HPP


#include <QtWidgets/QWidget>

/*!
 * Widget, which contains all the settings needed for communiacting with RaspberryPi
 */
class SettingsTab : public QWidget {
Q_OBJECT
public:
    SettingsTab(const SettingsTab &rhs) = delete;

    SettingsTab(const SettingsTab &&rhs) = delete;

    /*!
     * default Qt-like constructor
     *
     * @param parent Qt-like parameter for widget.
     */
    SettingsTab(QWidget *parent = nullptr);

    /*!
     * Slot for managing clickability of widgets.
     */
    Q_SLOT void enable(bool enabled);

    ~SettingsTab() = default;

private:
    Q_SIGNAL void changeEnable(bool);
};


#endif //PIMANAGER_SETTINGSTAB_HPP
