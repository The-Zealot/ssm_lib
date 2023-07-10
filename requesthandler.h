#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QObject>

#include "ssm_lib_global.h"
#include "request.h"
#include "reply.h"

class SSM_LIB_EXPORT RequestHandler
{
public:
    RequestHandler();

    void setRequest(Request &request);
    Request* request();

    virtual Reply handle() = 0;

protected:
    Request* _request;
};

#endif // REQUESTHANDLER_H
