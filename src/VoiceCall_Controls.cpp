#include "voicecall_controls.h"
#include "ui_voicecall_controls.h"

#include "gui_handler.h"

#include <QMessageBox>
#include <QSlider>
#include <QPushButton>

//
VoiceCall_Controls::VoiceCall_Controls(GUI_Handler* _gui_handler, QWidget* parent)
  : QWidget(parent), gui_handler(_gui_handler), ui(new Ui::VoiceCall_Controls),
    making_call(false), active_call_id(0), vol_muted(false), mic_muted(false), last_vol_lvl(255), last_mic_lvl(255)
{
  ui->setupUi(this);

  ui->verticalSlider_vol->setMinimum(0);
  ui->verticalSlider_mic->setMinimum(0);
  ui->verticalSlider_vol->setMaximum(255);
  ui->verticalSlider_mic->setMaximum(255);

  QObject::connect(ui->verticalSlider_vol, SIGNAL(sliderMoved(int)), this, SLOT(vol_changed(int)));
  QObject::connect(ui->verticalSlider_mic, SIGNAL(sliderMoved(int)), this, SLOT(mic_changed(int)));

  QObject::connect(ui->pushButton_muteVol, SIGNAL(clicked()), this, SLOT(mute_vol()));
  QObject::connect(ui->pushButton_muteMic, SIGNAL(clicked()), this, SLOT(mute_mic()));

  QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(make_call()));
  QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(make_call()));

  //
  this->update_ui();
  this->registered(false);
  this->set_vol( last_vol_lvl );
  this->set_mic( last_mic_lvl );

  ui->label_info->clear();
  ui->label_status->clear();
}

VoiceCall_Controls::~VoiceCall_Controls()
{
  delete ui;
}

void VoiceCall_Controls::registered(bool b)
{
  ui->pushButton->setEnabled(b);

  QVariantMap account_info = gui_handler->getAccountInformation();
  ui->label_info->setText("Registered as: '" +  account_info["address"].toString() + "'");
}

void VoiceCall_Controls::update_ui()
{
  if( !making_call )
  {
    ui->pushButton->setText("Call");

    ui->verticalSlider_vol->setEnabled(false);
    ui->verticalSlider_mic->setEnabled(false);
    ui->pushButton_muteVol->setEnabled(false);
    ui->pushButton_muteMic->setEnabled(false);
  }
  else
  {
    ui->pushButton->setText("End call");

    ui->verticalSlider_vol->setEnabled(true);
    ui->verticalSlider_mic->setEnabled(true);
    ui->pushButton_muteVol->setEnabled(true);
    ui->pushButton_muteMic->setEnabled(true);
  }
}

bool VoiceCall_Controls::incoming_call(int call_id, const QString& url, const QString& name)
{
  QString text = ( "New call: '" + QString::number(call_id) + "', '" + url + "', '" + name + "'" );

  ui->label_status->setText(text);

  int ret = QMessageBox::information(this, "Incoming call", text, QMessageBox::Ok | QMessageBox::Cancel, QMessageBox::Ok);
  bool result = bool( ret == QMessageBox::Ok );

  if( result )
  {
    making_call = true;
    active_call_id = call_id;

    this->update_ui();

    QString ll = ( "Talking with: '" + QString::number(call_id) + "', '" + url + "', '" + name + "'" );
    ui->label_status->setText(ll);
  }
  else
  {
    ui->label_status->clear();
  }
  return result;
}

void VoiceCall_Controls::call_ended(int call_id)
{
  QString text = "Call " + QString::number(call_id) + " ended";
//  QMessageBox::information(this, "***", text);

//  ui->label_status->clear();
  ui->label_status->setText(text);
  making_call = false;
  this->update_ui();
}

void VoiceCall_Controls::make_call()
{
  if( !gui_handler->checkAccountStatus() )
  {
    return;
  }

  QString dest = ui->lineEdit->text();

  if( !making_call && dest.isEmpty() )
  {
    return;
  }

  making_call = !making_call;
  this->update_ui();

  if( making_call )
  {
    QString url = "sip:" + dest + "@192.168.1.106:5060";
    active_call_id = gui_handler->makeCall( url );

    QString ll = ( "Calling '" + url + "'" );
    ui->label_status->setText(ll);
  }
  else
  {
    gui_handler->hangup( active_call_id );
//    ui->label_status->clear();

    QString text = "Call " + QString::number(active_call_id) + " ended";
    ui->label_status->setText(text);
  }
}

void VoiceCall_Controls::set_vol(int i)
{
  ui->verticalSlider_vol->setValue(i);
}

void VoiceCall_Controls::set_mic(int i)
{
  ui->verticalSlider_mic->setValue(i);
}

void VoiceCall_Controls::vol_changed(int i)
{
  if( !making_call )
  {
    return;
  }

  if( !i )
  {
    vol_muted = true;
  }
  else if( vol_muted )
  {
    vol_muted = false;
    gui_handler->muteSound(false, active_call_id);
  }

  gui_handler->setSoundLevel(active_call_id, i);
}

void VoiceCall_Controls::mic_changed(int i)
{
  if( !making_call )
  {
    return;
  }

  gui_handler->setMicrophoneLevel(active_call_id, i);
}

void VoiceCall_Controls::mute_vol()
{
  if( !making_call )
  {
    return;
  }

  vol_muted = !vol_muted;

  if( vol_muted )
  {
    last_vol_lvl = ui->verticalSlider_vol->value();

    ui->pushButton_muteVol->setText("Unmute");
    ui->verticalSlider_vol->setEnabled(false);
    ui->verticalSlider_vol->setValue(0);
  }
  else
  {
    ui->pushButton_muteVol->setText("Vol");
    ui->verticalSlider_vol->setEnabled(true);
    ui->verticalSlider_vol->setValue( last_vol_lvl );
  }

  // must be after all interface updates
  gui_handler->muteSound(vol_muted, active_call_id);
}

void VoiceCall_Controls::mute_mic()
{
  if( !making_call )
  {
    return;
  }

  mic_muted = !mic_muted;

  if( mic_muted )
  {
    last_mic_lvl = ui->verticalSlider_mic->value();

    ui->pushButton_muteMic->setText("Unmute");
    ui->verticalSlider_mic->setEnabled(false);
    ui->verticalSlider_mic->setValue(0);
  }
  else
  {
    ui->pushButton_muteMic->setText("Mic");
    ui->verticalSlider_mic->setEnabled(true);
    ui->verticalSlider_mic->setValue( last_mic_lvl );
  }

  // must be after all interface updates
  gui_handler->muteMicrophone(mic_muted, active_call_id);
}
