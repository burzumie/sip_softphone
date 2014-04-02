#include "e.h"

#include "Config.h"
#include "LogHandler.h"
#include "phone/Phone.h"
#include "Gui.h"

#include <QApplication>
#include <QBoxLayout>

//-----------------------------------------------------------------------------
Gui::Gui(phone::Phone &phone, QWidget *parent, Qt::WindowFlags flags) :
    QMainWindow(parent, flags),
    phone_(phone)
{
    qRegisterMetaType<LogInfo>("LogInfo");

    gui_handler_ = new GUI_Handler(phone_);
    phone_.set_GUI_Handler(gui_handler_);

    this->setup_UI( gui_handler_->get_main_widget() );

    connect(&LogHandler::getInstance(), SIGNAL(signalLogMessage(const LogInfo&)),
            gui_handler_,               SLOT(slotLogMessage(const LogInfo&)));

    connect(&phone_, SIGNAL(signalIncomingCall(const QString&, const QVariantMap&)),
            this,    SLOT(slotIncomingCall(const QString&, const QVariantMap&)));

  //
  QString host = "192.168.1.106";
  QString login = "1001";
  QString password = "";
  gui_handler_->registerToServer(host, login, password);
}

//-----------------------------------------------------------------------------
Gui::~Gui()
{
  gui_handler_->unregisterFromServer();

    delete gui_handler_;
}

void Gui::setup_UI(QWidget* main_widget)
{
  QMainWindow::resize(400, 300);
  QWidget* centralWidget = new QWidget(this);
  QMainWindow::setCentralWidget(centralWidget);
  QHBoxLayout* horizontalLayout = new QHBoxLayout(centralWidget);
  horizontalLayout->addWidget(main_widget);
}

//-----------------------------------------------------------------------------
void Gui::closeEvent(QCloseEvent *event)
{
    phone_.unregister();
    event->accept();
}

//-----------------------------------------------------------------------------
void Gui::slotIncomingCall(const QString& /* url */, const QVariantMap& /* header_map */)
{
    QApplication::alert(this);
}
