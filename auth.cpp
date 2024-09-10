#include "auth.h"
#include "ui_auth.h"
#include <QFile>
#include <QMessageBox>

Auth::Auth(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Auth)
{
    ui->setupUi(this);
}

Auth::~Auth()
{
    delete ui;
}

void Auth::on_pushButton_clicked()
{
    QString user_login = ui -> login1 -> toPlainText();
    QString user_password = ui -> password2 -> toPlainText();

    findData(user_login, user_password);

}

void Auth::findData(const QString &login, const QString &pass)
{
    bool login_em = false;
    bool pass_em = false;

    QFile file("D:/Programms/QT Projects/LoginAppDB/data.txt");

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString content = in.readAll();
        int login_index = content.indexOf(login, 0, Qt::CaseInsensitive);
        int pass_index = content.indexOf(pass, 0, Qt::CaseInsensitive);

        if (login_index != -1) {
            qDebug() << "Логин найден";
            login_em = true;
        } else {
            qDebug() << "Логин не найден!";
        }

        if (pass_index != -1) {
            qDebug() << "Пароль найден";
            pass_em = true;
        } else {
            qDebug() << "Пароль не найден!";
        }

        file.close();
    } else {
        qDebug() << "Ошибка открытия файла!";
    }

    if (login_em && pass_em){
        QMessageBox::information(this, "Авторизация", "Ваш аккаунт создан! Авторизация успешна");

    } else {
        QMessageBox::information(this, "Авторизация", "Ваш аккаунт ещё не создан. Зарегистрируйтесь!");

    }




}
