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

    bool execute(const QString requset, Reply &reply);

private:
    static void getSsmVersion(Reply &reply);

protected:
    QMap<QString, void(*)(Reply&)> _requestMap;
};

#endif // REQUESTEXECUTOR_H
