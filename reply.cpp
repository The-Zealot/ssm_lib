#include "reply.h"

Reply::Reply()
{
    _requestHeader  = "";
    _error          = true;
    _errorText      = "Unknown request";
}

Reply::Reply(QByteArray &reply)
{
    QJsonObject jObject = QJsonDocument::fromJson(reply).object();

    _requestHeader  = jObject["head"].toString();
    _error          = jObject["error"].toBool();
    _errorText      = jObject["errorText"].toString();

    if (!_error)
    {
        _body = jObject["body"].toObject();
    }

}

Reply::Reply(const QString &requestHeader, bool error, const QString &errorText, const QJsonObject &body)
{
    setReply(requestHeader, error, errorText, body);
}

void Reply::setReply(const QString &requestHeader, bool error, const QString &errorText, const QJsonObject &body)
{
    _requestHeader  = requestHeader;
    _error          = error;
    _errorText      = errorText;

    if (!_error)
    {
        _body = body;
    }
}

QString Reply::requestHeader()
{
    return _requestHeader;
}

bool Reply::error()
{
    return _error;
}

QString Reply::errorText()
{
    return _errorText;
}

QJsonObject Reply::body()
{
    return _body;
}

QByteArray Reply::serialize()
{
    QJsonObject jObject;
    jObject["head"]         = _requestHeader;
    jObject["error"]        = _error;
    jObject["errorText"]    = _errorText;
    jObject["body"]         = _body;

    return QJsonDocument(jObject).toJson();
}
