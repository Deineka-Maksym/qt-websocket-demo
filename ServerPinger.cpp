#include "ServerPinger.h"

ServerPinger::ServerPinger(QPointer<QWebSocket> webSocket, QObject *parent) :
    QObject(parent),
    webSocket_(webSocket)
{

}
