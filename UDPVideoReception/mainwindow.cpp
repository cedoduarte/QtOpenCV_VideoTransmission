#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QUdpSocket>
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create a UDP socket
    m_udpSocket = new QUdpSocket(this);
    qDebug() << "bind?" << m_udpSocket->bind(QHostAddress::Any, PORT);
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &MainWindow::processDatagrams);

    qDebug() << "Client ready to receive video...";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processDatagrams()
{
    qDebug() << "datagram arrived";
    while (m_udpSocket->hasPendingDatagrams())
    {
        QByteArray buffer;
        buffer.resize(MAX_BUFFER_SIZE);
        QHostAddress sender;
        quint16 senderPort;

        int bytesRead = m_udpSocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
        if (bytesRead == -1)
        {
            qWarning("Error: Failed to receive frame.");
            return;
        }

        // Decode the frame using QByteArray data
        std::vector<uchar> byteVector(buffer.data(), buffer.data() + bytesRead);
        cv::Mat frame = cv::imdecode(byteVector, cv::IMREAD_COLOR);
        if (frame.empty())
        {
            qWarning("Error: Decoded empty frame.");
            return;
        }

        // Convert OpenCV Mat to QImage and emit signal
        QImage img = QImage(frame.data, frame.cols, frame.rows, frame.step[0], QImage::Format_BGR888);
        ui->label->setPixmap(QPixmap::fromImage(img));
    }
}
