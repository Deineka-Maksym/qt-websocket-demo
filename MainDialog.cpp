#include "MainDialog.h"
#include "ui_MainDialog.h"

MainDialog::MainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainDialog)
{
    ui->setupUi(this);
    ui->disconnectButton->setEnabled(false);
    ui->mouseButton->setEnabled(false);
    ui->keyboardButton->setEnabled(false);
}

MainDialog::~MainDialog()
{
    delete ui;
}

void MainDialog::on_connectButton_clicked()
{
    QString fullAddress;

    QString address = ui->addressLineEdit->text();

    if (ui->addressLineEdit->text().contains("/")) {
        QString domain = address.left(ui->addressLineEdit->text().indexOf("/"));
        QString path = address.mid(address.indexOf("/"), address.size() - 1);
        fullAddress = "ws://" + domain + ":" + ui->portLineEdit->text() + path;
    } else {
        fullAddress = "ws://" + address + ":" + ui->portLineEdit->text();
    }

    qDebug() << "Full address:" << fullAddress;
    connectionManager_= new ConnectionManager(QUrl(fullAddress));

    connect(connectionManager_, &ConnectionManager::stateChanged, this, &MainDialog::onConnectionStateChanged);
    connect(connectionManager_, &ConnectionManager::textMessageReceived, this, &MainDialog::onTextMessageReceived);
}

void MainDialog::on_disconnectButton_clicked()
{
    connectionManager_->disconnect();
}

void MainDialog::on_mouseButton_clicked()
{
    connectionManager_->sentTextMessage(EventGenerator::getEvent(QString("mouse")));
}

void MainDialog::on_keyboardButton_clicked()
{
    connectionManager_->sentTextMessage(EventGenerator::getEvent(QString("keyboard")));
}

void MainDialog::on_clearButton_clicked()
{
    ui->logTextEdit->clear();
}

void MainDialog::on_testButton_clicked()
{
    connectionManager_->sentTextMessage("{\"from\":\"Maxim\",\"text\":\"My test message\"}");
}

void MainDialog::onConnectionStateChanged()
{
    ui->disconnectButton->setEnabled(connectionManager_->isConnected());
    ui->mouseButton->setEnabled(connectionManager_->isConnected());
    ui->keyboardButton->setEnabled(connectionManager_->isConnected());
    ui->connectButton->setDisabled(connectionManager_->isConnected());
}

void MainDialog::onTextMessageReceived(QString message)
{
    ui->logTextEdit->appendPlainText(message);
}
