#ifndef REQUESTEXECUTOR_H
#define REQUESTEXECUTOR_H

#include <QObject>
#include <QMap>

#include "ssm_lib_global.h"
#include "reply.h"

class SSM_LIB_EXPORT RequestExecutor
{
public:
    RequestExecutor();

    bool execute(const QString requset, Reply &reply, QJsonObject body = QJsonObject());

private:
    static void getSsmVersion(Reply &reply, QJsonObject params = QJsonObject());

protected:
    QMap<QString, void(*)(Reply&, QJsonObject)> _requestMap;
};

#endif // REQUESTEXECUTOR_H
