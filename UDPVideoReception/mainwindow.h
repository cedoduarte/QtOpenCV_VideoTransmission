#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#define PORT 3333
#define MAX_BUFFER_SIZE 65507 // Maximum size for UDP packet

class QUdpSocket;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void processDatagrams();
private:
    Ui::MainWindow *ui;
    QUdpSocket *m_udpSocket;
};

#endif // MAINWINDOW_H
