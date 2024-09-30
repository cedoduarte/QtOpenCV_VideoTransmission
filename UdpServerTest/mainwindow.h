#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QUdpSocket;
class RandomNumberThread;

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
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_actionClose_triggered();
private:
    Ui::MainWindow *ui;
    QUdpSocket *m_udpSocket;
    RandomNumberThread *m_thread;
};

#endif // MAINWINDOW_H
