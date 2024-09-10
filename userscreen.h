#ifndef USERSCREEN_H
#define USERSCREEN_H

#include <QMainWindow>

namespace Ui {
class UserScreen;
}

class UserScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserScreen(QWidget *parent = nullptr);
    ~UserScreen();

private:
    Ui::UserScreen *ui;
};

#endif // USERSCREEN_H
