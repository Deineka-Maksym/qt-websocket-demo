 #ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPointer>
#include "ConnectionManager.h"
#include "EventGenerator.h"

namespace Ui {
class MainDialog;
}

class MainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MainDialog(QWidget *parent = 0);
    ~MainDialog();

private slots:
    void on_connectButton_clicked();
    void on_disconnectButton_clicked();
    void on_mouseButton_clicked();
    void on_keyboardButton_clicked();
    void on_clearButton_clicked();
    void on_testButton_clicked();
    void onConnectionStateChanged();
    void onTextMessageReceived(QString message);

private:
    Ui::MainDialog *ui;
    QPointer<ConnectionManager> connectionManager_;
};

#endif // MAINDIALOG_H
