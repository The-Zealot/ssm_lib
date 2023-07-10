#include "request.h"

Request::Request(QByteArray &request)
{
    QJsonObject jObject = QJsonDocument::fromJson(request).object();

    _type = jObject["type"].toString();
    _head = jObject["head"].toString();
    _body = jObject["body"].toObject();
    _pass = jObject["pass"].toString();

    errorCheck();
}

Request::Request(QString &type, QString &head, QJsonObject &body, QString &pass)
{
    _type = type;
    _head = head;
    _body = body;
    _pass = pass;

    errorCheck();
}

QString Request::type()
{
    return _type;
}

QString Request::head()
{
    return _head;
}

QString Request::pass()
{
    return _pass;
}

QJsonObject Request::body()
{
    return _body;
}

Request::RequestError Request::error()
{
    return _error;
}

QByteArray Request::serialize()
{
    QJsonObject jObject;
    jObject["type"] = _type;
    jObject["head"] = _head;
    jObject["body"] = _body;
    jObject["pass"] = _pass;

    return QJsonDocument(jObject).toJson();
}

void Request::errorCheck()
{
    if (_type != REQUEST_TYPE_GET and
        _type != REQUEST_TYPE_SEND)
    {
        _error = INVALID_REQUEST;
    }

    _error = NO_ERROR;
}
