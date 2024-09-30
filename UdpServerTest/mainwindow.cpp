#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "randomnumberthread.h"

#include <QUdpSocket>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_udpSocket = new QUdpSocket(this);
    m_thread = new RandomNumberThread(this);

    connect(m_thread, &RandomNumberThread::newNumber, this, [&](int number)
    {
        QByteArray data = QByteArray::number(number);
        m_udpSocket->writeDatagram(data.data(), data.size(), QHostAddress::Broadcast, 3333);
        qDebug() << data << "was sent";
    });

    m_thread->start(QThread::HighestPriority);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    m_thread->terminate();
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

