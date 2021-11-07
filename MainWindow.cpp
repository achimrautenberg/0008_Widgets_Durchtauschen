#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Dlg_Login.h"
#include <QApplication>
#include <QMessageBox>
#include "Widget_Accounts.h"
#include "Widget_Plugins.h"
#include <QLayout>

MainWindow * pInstance = nullptr;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
	pInstance = this;
	m_pUi = new Ui::MainWindow();
	m_pUi->setupUi(this);
	m_bLoggedIn = false;
	m_pUi->centralwidget->setLayout(new QHBoxLayout());
}

MainWindow::~MainWindow()
{
	delete m_pUi;
}

void MainWindow::switchWidget(const WIDGET & w) {
	QWidget * pW = pInstance->initNewWidget(w);
	if(!pW) return;
	pInstance->clearLayout();
	pInstance->addNewWidget(pW);
}

QWidget * MainWindow::initNewWidget(const WIDGET & w) {
	QWidget * pW = nullptr;

	switch(w){
		case eWidget_Accounts:
			pW = new Widget_Accounts(pInstance);
			break;
		case eWidget_Plugins:
			pW = new Widget_Plugins(pInstance);
			break;
		default:
			return nullptr;
	}
	return pW;
}

void MainWindow::addNewWidget(QWidget * pW) {
	m_pUi->centralwidget->layout()->addWidget(pW);
}

void MainWindow::clearLayout() {
	QLayout * pLayout = m_pUi->centralwidget->layout();
	while(pLayout->count()) {
		QLayoutItem * pChild = pLayout->takeAt(0);
		delete pChild->widget();
		delete pChild;
	}
}

void MainWindow::showEvent(QShowEvent *event) {
	QMainWindow::showEvent(event);
	QMetaObject::invokeMethod(this , "onShown" , Qt::ConnectionType::QueuedConnection);
}

void MainWindow::onShown() {
	if(m_bLoggedIn == false) {
		Dlg_Login dlgLogin(this);
		int iRet = dlgLogin.exec();
		if(iRet == QDialog::Accepted){
			Common::setAccount(dlgLogin.account());
			m_bLoggedIn = true;
			switchWidget(MainWindow::eWidget_Accounts);
		}
	}
}
