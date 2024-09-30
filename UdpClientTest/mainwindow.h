#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
private:
    Ui::MainWindow *ui;
    QUdpSocket *m_udpSocket;
};

#endif // MAINWINDOW_H
