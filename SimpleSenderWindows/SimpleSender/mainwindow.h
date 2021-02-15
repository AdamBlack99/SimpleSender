#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include "Models/model.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLayout *_sendLayout;
    QLayout *_recieveLayout;
    QPushButton *_sendButton;
    QPushButton *_listenButton;
    QLineEdit *_addressInput;
    QLineEdit *_messageInput;
    QLineEdit *_messageOutput;
    QLineEdit *_myAddressInput;
    QLabel *_senderBg;
    QLabel *_receiverBg;

    Model *_model;

public slots:
    void sendMessage();
    void listenForMessage();
    void displayMessage(QString message);

};

#endif // MAINWINDOW_H
