#ifndef SERVERPINGER_H
#define SERVERPINGER_H

#include <QObject>
#include <QThread>
#include <QWebSocket>
#include <QPointer>

class ServerPinger : public QObject
{
    Q_OBJECT
public:
    explicit ServerPinger(QPointer<QWebSocket> webSocket, QObject *parent = 0);

signals:

public slots:

private:
    QPointer<QWebSocket> webSocket_;
};

#endif // SERVERPINGER_H
