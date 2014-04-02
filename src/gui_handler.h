#pragma once

#include "e.h"

#include <QObject>
#include <QString>
#include <QVariant>

class LogInfo;
class VoiceCall_Controls;

namespace phone
{
    class Phone;
    class Call;
}

//
class GUI_Handler : public QObject
{
    Q_OBJECT

private:
    phone::Phone& phone_;
    VoiceCall_Controls* vc_controls;

public:
    static const QString OBJECT_NAME;

    //
    GUI_Handler(phone::Phone& phone);

    void accountStateChanged(const int state) const;
    void callState(const int call_id, const int code, const int last_status) const;

    void incomingCall(const phone::Call& call) const;
    void receivedIncomingTextMessage(int call_id, const QString& from, const QString& to, 
                                     const QString& contact, const QString& mime_type, 
                                     const QString& body) const;

    void soundLevel(int level) const;
    void microphoneLevel(int level) const;

    QWidget* get_main_widget();

private slots:
    void slotLogMessage(const LogInfo& info) const;

public slots:
    bool checkAccountStatus() const;

    QVariantMap getAccountInformation() const;

    bool registerToServer(const QString& host, const QString& user_name, const QString& password) const;
    void unregisterFromServer() const;

    int makeCall(const QString& number) const;   
    int makeCall(const QString& number, const QVariantMap& header_map) const;

    void callAccept(const int call_id, const int code = 200) const;
    void hangup(const int call_id) const;
    void hangupAll() const;

    void setLogLevel(const unsigned int log_level) const;

    QString getCallUserData(const int call_id) const;

    void setCallUserData(const int call_id, const QString& data) const;

    QVariantList getErrorLogData() const;

    void deleteErrorLogFile() const;

    bool addToConference(const int src_id, const int dst_id) const;
    bool removeFromConference(const int src_id, const int dst_id) const;

    int redirectCall(const int call_id, const QString& dst_uri) const;

    QVariantList getActiveCallList() const;

    void muteSound(const bool mute, const int call_id = -1) const;
    void muteMicrophone(const bool mute, const int call_id = -1) const;
    void setSoundLevel(const int level, const int call_id) const;
    void setMicrophoneLevel(const int level, const int call_id) const;

    QVariantMap getSignalInformation() const;
    
    void setCodecPriority(const QString& codec, int new_priority) const;

    QVariantMap getCodecPriorities() const;
    void setSoundDevice(const int input, const int output) const;

    QVariantList getSoundDevices() const;

    QVariant getOption(const QString& name) const;
    void setOption(const QString& name, const QVariant& option);

    bool sendLogMessage(const QVariantMap& log) const;
    QStringList getLogFileList() const;
    QString getLogFileContent(const QString& file_name) const;  
    void deleteLogFile(const QString& file_name) const;

    void sendDTMFDigits(const int call_id, const QString& digits) const;
};
