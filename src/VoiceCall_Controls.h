#pragma once

#include "e.h"

#include <QWidget>

class GUI_Handler;

namespace Ui
{
  class VoiceCall_Controls;
}

//
class VoiceCall_Controls : public QWidget
{
  Q_OBJECT

private:
  Ui::VoiceCall_Controls* ui;
  GUI_Handler* gui_handler;

  int active_call_id;

  bool making_call;
  void update_ui();

  bool vol_muted;
  bool mic_muted;
  int last_vol_lvl;
  int last_mic_lvl;

public:
  explicit VoiceCall_Controls(GUI_Handler* _gui_handler, QWidget* parent = 0);
  ~VoiceCall_Controls();

  void registered(bool b);
  bool incoming_call(int call_id, const QString& url, const QString& name);
  void call_ended(int call_id);

  void set_vol(int i);
  void set_mic(int i);

public slots:
  void make_call();

  void vol_changed(int i);
  void mic_changed(int i);

  void mute_vol();
  void mute_mic();
};
