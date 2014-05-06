#include "e.h"

#include "phone/Account.h"
#include "phone/Call.h"
#include "phone/Phone.h"
#include "LogHandler.h"
#include "Config.h"
#include "GUI_Handler.h"
#include "json.h"

#include "VoiceCall_Controls.h"

#include <QString>
#include <QMessageBox>

//
using phone::Phone;
using phone::Call;
using phone::Account;
//using QtJson::Json;

const QString GUI_Handler::OBJECT_NAME = "qt_handler";

//-----------------------------------------------------------------------------
GUI_Handler::GUI_Handler(Phone& phone)
  : phone_(phone)
{
  // not deleted in destructor, because must be added to some layout elsewhere in code
  vc_controls = new VoiceCall_Controls(this);
}

QWidget* GUI_Handler::get_main_widget()
{
  return vc_controls;
}

//-----------------------------------------------------------------------------
void GUI_Handler::accountStateChanged(const int state) const
{
// !!!
  bool rr = bool(state == 200);
  vc_controls->registered(rr);

  if( !rr )
  {
    QMessageBox::warning(vc_controls, "Warning", "Not registered on server, status code is: " + QString::number(state));
  }
}

//-----------------------------------------------------------------------------
void GUI_Handler::callState(const int call_id, const int code, 
                                  const int last_status) const
{
// !!!
//    QMessageBox::information(vc_controls, "Information", "State from call '" + QString::number(call_id) + "' changed from '" + QString::number(last_status) + "' to '" + QString::number(code) + "'");

/*
    // from 'phone-lib.js'
    STATUS_UNKNOWN:     -1,
    STATUS_RINGING:     0,
    STATUS_ACCEPTED:    1,
    STATUS_CLOSED:      2,
    STATUS_ERROR:       3,
    
    SIP_STATE_NULL:         0,      // Before INVITE is sent or received
    SIP_STATE_CALLING:      1,      // After INVITE is sent
    SIP_STATE_INCOMING:     2,      // After INVITE is received
    SIP_STATE_EARLY:        3,      // After response with To tag
    SIP_STATE_CONNECTING:   4,      // After 2xx is sent/received
    SIP_STATE_CONFIRMED:    5,      // After ACK is sent/received
    SIP_STATE_DISCONNECTED: 6       // Session is terminated
*/

  if( code == 6 )
  {
    vc_controls->call_ended(call_id);
  }
}

//-----------------------------------------------------------------------------
void GUI_Handler::incomingCall(const Call& call) const
{
// !!!
  int call_id = call.getId();
  if( vc_controls->incoming_call(call_id, call.getUrl(), call.getName()) )
  {
    this->callAccept(call_id);
  }
  else
  {
    this->hangup(call_id);
  }
}

//-----------------------------------------------------------------------------
void GUI_Handler::receivedIncomingTextMessage(int call_id, 
                                                    const QString& from, const QString& to, 
                                                    const QString& contact, 
                                                    const QString& mime_type, 
                                                    const QString& body) const
{
// !!!
}

//-----------------------------------------------------------------------------
void GUI_Handler::soundLevel(int level) const
{
// !!!
  vc_controls->set_vol(level);
}

//-----------------------------------------------------------------------------
void GUI_Handler::microphoneLevel(int level) const
{
// !!!
  vc_controls->set_mic(level);
}

//-----------------------------------------------------------------------------
bool GUI_Handler::checkAccountStatus() const
{
    return phone_.checkAccountStatus();
}

//-----------------------------------------------------------------------------
QVariantMap GUI_Handler::getAccountInformation() const
{
    return phone_.getAccountInfo();
}

//-----------------------------------------------------------------------------
bool GUI_Handler::registerToServer(const QString& host, const QString& user_name,
                                         const QString& password)
{
  voip_server = host;

    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "register"));

    Account acc;
    acc.setUsername(user_name);
    acc.setPassword(password);
    acc.setHost(host);

    return phone_.registerUser(acc);
}

//-----------------------------------------------------------------------------
void GUI_Handler::unregisterFromServer() const
{
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "unregister"));

    phone_.unregister();
}

//-----------------------------------------------------------------------------
int GUI_Handler::makeCall(const QString& number, const QVariantMap& header_map) const
{
    Call* call = phone_.makeCall(number, header_map);
    if( !call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "makeCall: failed"));
        return -1;
    }
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "calling " + number));
    return call->getId();
}

//-----------------------------------------------------------------------------
int GUI_Handler::makeCall(const QString& number) const
{
    Call* call = phone_.makeCall(number);
    if( !call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "makeCall: failed"));
        return -1;
    }
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "calling " + number));
    return call->getId();
}

//-----------------------------------------------------------------------------
void GUI_Handler::callAccept(const int call_id, const int code) const
{
    Call* call = phone_.getCall(call_id);
    if( call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "accepting call " + QString::number(call_id)));
        call->answerCall(code);
    } else
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "callAccept: Call doesn't exist!"));
    }
}

//-----------------------------------------------------------------------------
void GUI_Handler::hangup(const int call_id) const
{    
    Call* call = phone_.getCall(call_id);
    if( call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "hangup call " + QString::number(call_id)));
        call->hangUp();
    } else
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Hangup: Call doesn't exist!"));
    }
}

//-----------------------------------------------------------------------------
void GUI_Handler::hangupAll() const
{
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "hangup all calls"));
    phone_.hangUpAll();
}

//-----------------------------------------------------------------------------
void GUI_Handler::setLogLevel(const unsigned int log_level) const
{
    LogHandler::getInstance().setLevel(log_level);
}

//-----------------------------------------------------------------------------
QString GUI_Handler::getCallUserData(const int call_id) const
{
    Call* call = phone_.getCall(call_id);
    if( call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "Get userdata for call " + QString::number(call_id)));
        return call->getUserData();
    }
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "getCallUserData: Call doesn't exist!"));
    return "";
}

//-----------------------------------------------------------------------------
void GUI_Handler::setCallUserData(const int call_id, const QString& data) const
{
    Call* call = phone_.getCall(call_id);
    if( call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "Set userdata for call " + QString::number(call_id)));
        return call->setUserData(data);
    } else
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "setCallUserData: Call doesn't exist!"));
    }
}

//-----------------------------------------------------------------------------
QVariantList GUI_Handler::getErrorLogData() const
{
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "Read error log data"));

    QVariantList log_data;
    QFile file(Phone::ERROR_FILE);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);

    while( !in.atEnd() )
    {
        Call call;
        in >> call;
        log_data << call.getInfo();
    }

    return log_data;
}

//-----------------------------------------------------------------------------
void GUI_Handler::deleteErrorLogFile() const
{
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "Delete error log file"));

    QFile::remove(Phone::ERROR_FILE);
}

//-----------------------------------------------------------------------------
bool GUI_Handler::addToConference(const int src_id, const int dst_id) const
{
    Call* call = phone_.getCall(src_id);
    Call* dest_call = phone_.getCall(dst_id);
    if( !call || !dest_call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: one of the selected calls doesn't exist!"));
        return false;
    }
    if( !call->isActive() || !dest_call->isActive() )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: one of the selected calls isn't active!"));
        return false;
    }
    if( !call->addToConference(*dest_call) )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: failed to connect to source!"));
        return false;
    }
    if( !dest_call->addToConference(*call) )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: failed to connect to destination!"));
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------
bool GUI_Handler::removeFromConference(const int src_id, const int dst_id) const
{
    Call* call = phone_.getCall(src_id);
    Call* dest_call = phone_.getCall(dst_id);
    if( !call || !dest_call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: one of the selected calls doesn't exist!"));
        return false;
    }
    if( !call->isActive() || !dest_call->isActive() )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: one of the selected calls isn't active!"));
        return false;
    }
    if( call->removeFromConference(*dest_call) )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: failed to remove from source!"));
        return false;
    }
    if( dest_call->removeFromConference(*call) )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "Error: failed to remove from destination!"));
        return false;
    }
    return true;
}

//-----------------------------------------------------------------------------
int GUI_Handler::redirectCall(const int call_id, const QString& dst_uri) const
{
    Call* call = phone_.getCall(call_id);
    if( call )
    {
        LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_DEBUG, "gui_handler", 0, "Redirected call " + QString::number(call_id) + " to " + dst_uri));
        return call->redirect(dst_uri);
    }
    LogHandler::getInstance().log(LogInfo(LogInfo::STATUS_ERROR, "gui_handler", 0, "redirectCall: Call doesn't exist!"));
    return -1;
}

//-----------------------------------------------------------------------------
QVariantList GUI_Handler::getActiveCallList() const
{
    return phone_.getActiveCallList();
}

//-----------------------------------------------------------------------------
void GUI_Handler::muteSound(const bool mute, const int call_id) const
{
    if( call_id < 0 )
    {
        phone_.setSoundSignal(mute ? 0.0f : 1.0f);
    }
    else
    {
        Call* call = phone_.getCall(call_id);
        if( call )
        {
            call->setSoundSignal(mute ? 0.0f : 1.0f);
        }
    }
}

//-----------------------------------------------------------------------------
void GUI_Handler::muteMicrophone(const bool mute, const int call_id) const
{
    if( call_id < 0 )
    {
        phone_.setMicroSignal(mute ? 0.0f : 1.0f);
    }
    else
    {
        Call* call = phone_.getCall(call_id);
        if( call )
        {
            call->setMicroSignal(mute ? 0.0f : 1.0f);
        }
    }
}

//-----------------------------------------------------------------------------
void GUI_Handler::setSoundLevel(const int level, const int call_id) const
{
    float flevel = static_cast<float>(level) / 255.f;
    if( flevel > 1.0f )
    {
        flevel = 1.0f;
    }
    else
    if( flevel < 0.0f )
    {
        flevel = 0.0f;
    }
    
    if( call_id < 0 )
    {
        phone_.setSoundSignal(flevel);
    }
    else
    {
        Call* call = phone_.getCall(call_id);
        if( call )
        {
            call->setSoundSignal(flevel);
        }
    }
}

//-----------------------------------------------------------------------------
void GUI_Handler::setMicrophoneLevel(const int level, const int call_id) const
{
    float flevel = static_cast<float>(level) / 255.f;
    if( flevel > 1.0f )
    {
        flevel = 1.0f;
    }
    else
    if( flevel < 0.0f )
    {
        flevel = 0.0f;
    }
    
    if( call_id < 0 )
    {
        phone_.setMicroSignal(flevel);
    }
    else
    {
        Call* call = phone_.getCall(call_id);
        if( call )
        {
            call->setMicroSignal(flevel);
        }
    }
}

//-----------------------------------------------------------------------------
QVariantMap GUI_Handler::getSignalInformation() const
{
    return phone_.getSignalLevels();
}

//-----------------------------------------------------------------------------
void GUI_Handler::setCodecPriority(const QString& codec, int new_priority) const
{
    phone_.setCodecPriority(codec, new_priority);
}

//-----------------------------------------------------------------------------
QVariantMap GUI_Handler::getCodecPriorities() const
{
    return phone_.getCodecPriorities();
}

//-----------------------------------------------------------------------------
void GUI_Handler::setSoundDevice(const int input, const int output) const
{
    phone_.setSoundDevice(input, output);
}

//-----------------------------------------------------------------------------
QVariantList GUI_Handler::getSoundDevices() const
{
    return phone_.getSoundDevices();
}

//-----------------------------------------------------------------------------
QVariant GUI_Handler::getOption(const QString& name) const
{
    return Config::getInstance().getOption(name);
}

//-----------------------------------------------------------------------------
void GUI_Handler::setOption(const QString& name, const QVariant& option)
{
    Config::getInstance().setOption(name, option);
}

//-----------------------------------------------------------------------------
bool GUI_Handler::sendLogMessage(const QVariantMap& log) const
{
    QVariant time   = log["time"];
    QVariant status = log["status"];
    QVariant domain = log["domain"];
    QVariant code   = log["code"];
    QVariant msg    = log["message"];

    if (!time.convert(QVariant::String) || !status.convert(QVariant::UInt)
        || !domain.convert(QVariant::String) || !code.convert(QVariant::Int)
        || !msg.convert(QVariant::String))
    {
        return false;
    }

    LogInfo info((LogInfo::Status)status.toUInt(), domain.toString(), code.toInt(), msg.toString());
    info.time_.fromString(time.toString(), "dd.MM.yyyy hh:mm:ss");

    LogHandler::getInstance().log(info, false);
    return true;
}

//-----------------------------------------------------------------------------
QStringList GUI_Handler::getLogFileList() const
{
    return LogHandler::getInstance().getFileList();
}

//-----------------------------------------------------------------------------
QString GUI_Handler::getLogFileContent(const QString& file_name) const
{
    return LogHandler::getInstance().getFileContent(file_name);
}

//-----------------------------------------------------------------------------
void GUI_Handler::deleteLogFile(const QString& file_name) const
{
    LogHandler::getInstance().deleteFile(file_name);
}

//-----------------------------------------------------------------------------
void GUI_Handler::sendDTMFDigits(const int call_id, const QString& digits) const
{
    Call* call = phone_.getCall(call_id);
    if( call )
    {
        call->sendDTMFDigits(digits);
    }
}

//-----------------------------------------------------------------------------
void GUI_Handler::slotLogMessage(const LogInfo& info) const
{
}
