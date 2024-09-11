#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include "dialog.h"
#include "auth.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString user_name = ui -> name -> toPlainText();
    QString user_lastName = ui -> last_name -> toPlainText();
    QString user_number = ui -> number -> toPlainText();
    QString login = ui -> login -> toPlainText();
    QString user_pass = ui -> pass -> text();

    QString user_info = "Имя пользователя: " + user_name + "\nФамилия пользователя: " + user_lastName + "\nНомер телефона: " + user_number;
    QString user_data = "Данные пользователя:\nЛогин: " + login + "\nПароль: " + user_pass;
    QString lp_form = login + ";" + user_pass + "|";

    qDebug() << user_info;
    qDebug() << user_data;

    bool number_status = check_number(user_number);
    int number_length = user_number.size();
    bool name_status = check_name(user_name);
    bool last_name_status = check_name(user_lastName);
    int pass_length = user_pass.size();

    if (name_status == false || last_name_status == false){
        QMessageBox::information(this, "Авторизация", "Найдены цифры в имени или фамилии");
    } else if (number_status == false || number_length < 7){
        QMessageBox::information(this, "Авторизация", "Номер введён неверно!");
    } else if (pass_length < 5){
        QMessageBox::information(this, "Авторизация", "Пароль должен быть состоять не менее чем из 5 символов!");

    } else {
        saveData(lp_form);
        QFile file("D:/Programms/QT Projects/LoginAppDB/info.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << user_info << Qt::endl;
            file.close();
            qDebug() << "Инфа записана в файл";
        } else {
            qDebug() << "Ошибка!";
        }
        Dialog *window = new Dialog();
        connect(this, &MainWindow::send_data, window, &Dialog::recieveUserData);
        emit send_data(user_name, user_lastName, user_number);
        window -> exec();
    }
}

bool MainWindow::check_number(const QString& str){

    for (int i = 0; i < str.size(); ++i){
        if (!str[i].isDigit()){
            return false;
        }
    }
    return true;
}

bool MainWindow::check_name(const QString& name){
    for (int i = 0; i < name.size(); ++i){
        if (name[i].isDigit()){
            return false;
        }
    }
    return true;

}

void MainWindow::on_pushButton_2_clicked()
{
    Auth window;
    window.setModal(true);
    window.exec();
}

void MainWindow::saveData(const QString &data)
{
    QFile file("D:/Programms/QT Projects/LoginAppDB/data.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << data << Qt::endl;
        file.close();
        qDebug() << "Логин и пароль сохранены!";
    } else {
        qDebug() << "Ошибка при сохранении логина и пароля!";
    }

}


