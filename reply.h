#ifndef REPLY_H
#define REPLY_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>

#include "ssm_lib_global.h"

class SSM_LIB_EXPORT Reply
{
public:
    Reply();
    Reply(QByteArray &reply);
    Reply(const QString &requestHeader, bool error, const QString &errorText, const QJsonObject &body);

    void setReply(const QString &requestHeader, bool error, const QString &errorText, const QJsonObject &body);

    QString requestHeader();
    bool error();
    QString errorText();
    QJsonObject body();

    QByteArray serialize();

private:
    QString _requestHeader;
    bool _error;
    QString _errorText;
    QJsonObject _body;
};

#endif // REPLY_H
