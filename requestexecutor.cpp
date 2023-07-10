#include "requestexecutor.h"

RequestExecutor::RequestExecutor()
{
    _requestMap.insert("getSsmVersion", getSsmVersion);
}

bool RequestExecutor::execute(const QString request, Reply &reply)
{
    _requestMap[request](reply);
}

void RequestExecutor::getSsmVersion(Reply &reply)
{
    QJsonObject body;
    body["version"] = "v0.1";
    body["note"]    = "first version of ssm library";

    reply.setReply("getSsmVersion", false, "", body);
}
