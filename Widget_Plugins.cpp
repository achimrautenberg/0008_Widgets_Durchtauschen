#include "Widget_Plugins.h"
#include "ui_Widget_Plugins.h"
#include "MainWindow.h"

Widget_Plugins::Widget_Plugins(QWidget *parent) : QWidget(parent) {
	ui = new Ui::Widget_Plugins();
	ui->setupUi(this);
	connect(ui->pushButton , SIGNAL(clicked()) , this , SLOT(onBtn()));
}

Widget_Plugins::~Widget_Plugins()
{
	delete ui;
}

void Widget_Plugins::onBtn() {
	MainWindow::switchWidget(MainWindow::eWidget_Accounts);
}
