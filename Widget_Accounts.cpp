#include "Widget_Accounts.h"
#include "ui_Widget_Accounts.h"
#include "MainWindow.h"

Widget_Accounts::Widget_Accounts(QWidget *parent) : QWidget(parent)
{
	ui = new Ui::Widget_Accounts();
	ui->setupUi(this);

	connect(ui->pushButton , SIGNAL(clicked()) , this , SLOT(onClicked()));
}

Widget_Accounts::~Widget_Accounts()
{
	delete ui;
}

void Widget_Accounts::onClicked() {
	MainWindow::switchWidget(MainWindow::eWidget_Plugins);
}
