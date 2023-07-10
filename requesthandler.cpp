#include "requesthandler.h"

RequestHandler::RequestHandler()
{

}

void RequestHandler::setRequest(Request &request)
{
    _request = &request;
}

Request *RequestHandler::request()
{
    return _request;
}
