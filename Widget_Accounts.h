#ifndef WIDGET_ACCOUNTS_H
#define WIDGET_ACCOUNTS_H

#include <QWidget>

namespace Ui {
	class Widget_Accounts;
}

class Widget_Accounts : public QWidget
{
	Q_OBJECT

private:
	Ui::Widget_Accounts *ui;

public:
	explicit Widget_Accounts(QWidget *parent = nullptr);
	~Widget_Accounts();

private slots:
	void onClicked();

};

#endif // WIDGET_ACCOUNTS_H
