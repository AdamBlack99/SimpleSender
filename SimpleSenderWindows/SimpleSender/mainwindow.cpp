#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Setting up the UI elements
    _sendLayout = new QGridLayout();
    ui->baseLayout->addLayout(_sendLayout, 1, 1);
    _recieveLayout = new QGridLayout();
    ui->baseLayout->addLayout(_recieveLayout, 1, 2);

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
    connect(_model, SIGNAL(gotMessage(std::string)), this, SLOT(displayMessage(std::string)));

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
void MainWindow::displayMessage(std::string message)
{
    _messageOutput->setText(QString::fromUtf8(message.c_str()));
}


MainWindow::~MainWindow()
{
    delete ui;
}
