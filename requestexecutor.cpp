#include "requestexecutor.h"

RequestExecutor::RequestExecutor()
{
    _requestMap.insert("getSsmVersion", getSsmVersion);
}

bool RequestExecutor::execute(const QString request, Reply &reply)
{
    if (!_requestMap.contains(request))
    {
        return false;
    }
    _requestMap[request](reply);
    return true;
}

void RequestExecutor::getSsmVersion(Reply &reply)
{
    QJsonObject body;
    body["version"] = "v0.1";
    body["note"]    = "first version of ssm library";

    reply.setReply("getSsmVersion", false, "", body);
}
