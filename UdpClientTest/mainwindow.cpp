#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QUdpSocket>

#define MAX_BUFFER_SIZE 65507 // Maximum size for UDP packet

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_udpSocket = new QUdpSocket(this);
    connect(m_udpSocket, &QUdpSocket::readyRead, this, [&]()
    {
        if (m_udpSocket->hasPendingDatagrams())
        {
            int size = m_udpSocket->pendingDatagramSize();
            QByteArray buffer;
            buffer.resize(size);
            QHostAddress sender;
            quint16 senderPort;

            int bytesRead = m_udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
            if (bytesRead == -1)
            {
                qDebug() << "Error: Failed to receive frame.";
                return;
            }

            qDebug() << "data arraived:" << buffer;
        }
    });

    qDebug() << "bind?" << m_udpSocket->bind(QHostAddress::Any, 3333);
}

MainWindow::~MainWindow()
{
    delete ui;
}
