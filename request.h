#ifndef REQUEST_H
#define REQUEST_H

#include <QObject>
#include <QJsonObject>
#include <QJsonDocument>
#include "ssm_lib_global.h"

#define REQUEST_TYPE_GET    "GET"
#define REQUEST_TYPE_SEND   "SEND"

class SSM_LIB_EXPORT Request
{
public:
    enum RequestError
    {
        NO_ERROR = 0,
        INVALID_REQUEST,
        UNKNOWN_REQUEST,
        ACCESS_DENIED,
    };

    Request(QByteArray &request);
    Request(QString &type, QString &head, QJsonObject &body, QString &pass);

    QString type();
    QString head();
    QString pass();
    QJsonObject body();
    RequestError error();

    QByteArray serialize();

private:
    void errorCheck();

private:
    QString _type;
    QString _head;
    QJsonObject _body;
    QString _pass;

    RequestError _error;
};

#endif // REQUEST_H
