#ifndef WIDGET_PLUGINS_H
#define WIDGET_PLUGINS_H

#include <QWidget>

namespace Ui {
	class Widget_Plugins;
}

class Widget_Plugins : public QWidget
{
	Q_OBJECT

private:
	Ui::Widget_Plugins *ui;

public:
	explicit Widget_Plugins(QWidget *parent = nullptr);
	~Widget_Plugins();

private slots:
	void onBtn();
};

#endif // WIDGET_PLUGINS_H
