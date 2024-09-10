#include "userscreen.h"
#include "ui_userscreen.h"

UserScreen::UserScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserScreen)
{
    ui->setupUi(this);
}

UserScreen::~UserScreen()
{
    delete ui;
}
