#pragma once

#include "e.h"

#include <QtGui>
#include <QString>
#include <QMainWindow>

#include "GUI_Handler.h"

class Gui : public QMainWindow
{
    Q_OBJECT

private:
    phone::Phone &phone_;
    GUI_Handler* gui_handler_;

    //
    void setup_UI(QWidget* main_widget);

protected:
    void closeEvent(QCloseEvent *event);

public:
    Gui(phone::Phone &phone, QWidget *parent = 0, Qt::WindowFlags flags = 0);
    virtual ~Gui();

private slots:
    void slotIncomingCall(const QString &url, const QVariantMap& header_map);
};
