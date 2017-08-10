#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QtWebSockets/QWebSocket>

class ConnectionManager : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionManager(const QUrl &url, QObject *parent = 0);
    void disconnect();
    bool isConnected();
    qint64 sentTextMessage(const QString &message);

signals:
    void closed();
    void stateChanged();
    void textMessageReceived(QString);

public slots:

private slots:
    void onConnectionStateChanged(QAbstractSocket::SocketState state);
    void onTextMessageReceived(QString message);
    void onConnected();
    void onClosed();
    void onConnectionError(QAbstractSocket::SocketError error);
    void onPongReceived(quint64 elapsedTime, const QByteArray &payload);

private:
    QWebSocket webSocket_;
    QUrl url_;
};

#endif // CONNECTIONMANAGER_H
