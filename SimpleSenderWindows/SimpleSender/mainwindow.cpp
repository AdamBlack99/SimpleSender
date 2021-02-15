#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Setting up the UI elements

    _senderBg = new QLabel();
    _senderBg->setAttribute(Qt::WA_StyledBackground, true);
    _senderBg->setStyleSheet("background-color: : red");
    _senderBg->setAutoFillBackground(true);
    ui->baseLayout->addWidget(_senderBg);

    _receiverBg = new QLabel();
    _receiverBg->setStyleSheet("background-color: : red");
    ui->baseLayout->addWidget(_receiverBg);

    _sendLayout = new QGridLayout(_senderBg);
    //ui->baseLayout->addLayout(_sendLayout, 1, 1);
    _recieveLayout = new QGridLayout(_receiverBg);
   // ui->baseLayout->addLayout(_recieveLayout, 1, 2);



    _addressInput = new QLineEdit();
    _addressInput->setPlaceholderText("Address IP");
    _sendLayout->addWidget(_addressInput);

    _messageInput = new QLineEdit();
    _messageInput->setPlaceholderText("Your Message");
    _sendLayout->addWidget(_messageInput);

    _sendButton = new QPushButton();
    _sendButton->setText("SEND");
    _sendLayout->addWidget(_sendButton);



    _messageOutput = new QLineEdit();
    _messageOutput->setPlaceholderText("The message you recieve will appear here");
    _recieveLayout->addWidget(_messageOutput);

    _myAddressInput = new QLineEdit();
    _myAddressInput->setPlaceholderText("Your IP");
    _recieveLayout->addWidget(_myAddressInput);

    _listenButton = new QPushButton();
    _listenButton->setText("Listen");
    _recieveLayout->addWidget(_listenButton);


    _model = new Model();

    //Connecting signals
    connect(_sendButton, SIGNAL(released()), this, SLOT(sendMessage()));
    connect(_listenButton, SIGNAL(released()), this, SLOT(listenForMessage()));
    connect(_model->_server, SIGNAL(received(QString)), this, SLOT(displayMessage(QString)));

}

void MainWindow::sendMessage()
{
    _model->send(_addressInput->text().toStdString(), _messageInput->text().toStdString());
}

void MainWindow::listenForMessage()
{
    _model->listen(_myAddressInput->text().toStdString());
}


//Triggers when the model recieves the message
void MainWindow::displayMessage(QString message)
{
    _messageOutput->setText(message);
}


MainWindow::~MainWindow()
{
    delete ui;
}
