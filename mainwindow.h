#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    bool check_number(const QString& str);

    void on_pushButton_2_clicked();
    void saveData(const QString &data);

signals:
    void send_data(const QString &name, const QString &last_name, const QString &number);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
