#include "ConnectionManager.h"

ConnectionManager::ConnectionManager(const QUrl &url, QObject *parent) :
    QObject(parent),
    url_(url)
{
    connect(&webSocket_, &QWebSocket::connected, this, &ConnectionManager::onConnected);
    connect(&webSocket_, &QWebSocket::disconnected, this, &ConnectionManager::onClosed);
    connect(&webSocket_, &QWebSocket::stateChanged, this, &ConnectionManager::onConnectionStateChanged);
    connect(&webSocket_, &QWebSocket::textMessageReceived, this, &ConnectionManager::onTextMessageReceived);
    connect(&webSocket_, static_cast<void(QWebSocket::*)(QAbstractSocket::SocketError)>(&QWebSocket::error), this, &ConnectionManager::onConnectionError);
    connect(&webSocket_, &QWebSocket::pong, this, &ConnectionManager::onPongReceived);

    webSocket_.open(url);
}

void ConnectionManager::disconnect()
{
    webSocket_.close();
}

bool ConnectionManager::isConnected()
{
    return QAbstractSocket::ConnectedState == webSocket_.state();
}

qint64 ConnectionManager::sentTextMessage(const QString &message)
{
    return webSocket_.sendTextMessage(message);
}

void ConnectionManager::onConnectionStateChanged(QAbstractSocket::SocketState state)
{
    Q_UNUSED(state)
    emit stateChanged();
}

void ConnectionManager::onTextMessageReceived(QString message)
{
    emit textMessageReceived(message);
}

void ConnectionManager::onConnected()
{
    webSocket_.ping();
    qDebug() << "Connected!";
}

void ConnectionManager::onClosed()
{
    qDebug() << "Disconnected!";
}

void ConnectionManager::onConnectionError(QAbstractSocket::SocketError error)
{
    qDebug() << "Error:" << error;
}

void ConnectionManager::onPongReceived(quint64 elapsedTime, const QByteArray &payload)
{
    qDebug() << "Pong:" << elapsedTime;
}
