#include "Dlg_Login.h"
#include "ui_Dlg_Login.h"
#include <QMessageBox>


Dlg_Login::Dlg_Login(QWidget *parent) : QDialog(parent) {
	ui = new Ui::Dlg_Login();
	ui->setupUi(this);

	loadAccounts();

	connect(ui->btnLogin , SIGNAL(clicked()) , this , SLOT(onBtnLogin()));
}

Dlg_Login::~Dlg_Login()
{
	delete ui;
}

const Account & Dlg_Login::account() const {
	return m_account;
}

void Dlg_Login::loadAccounts() {
	QString sFilename = qApp->applicationDirPath() + "/accounts.json";
	m_lstAccounts = Account::fromJsonFile(sFilename);
}

bool Dlg_Login::isAccountValid(const Account & account) {
	for(int i = 0 ; i < m_lstAccounts.count() ; i++) {
		Account acc = m_lstAccounts[i];
		if(acc.username() == account.username()) {
			if(acc.password() == account.password()) {
				return true;
			}
		}
	}
	return false;
}

void Dlg_Login::onBtnLogin() {
	Account account;
	account.setUsername(ui->txtUsername->text());
	account.setPassword(ui->txtPassword->text());
	if(isAccountValid(account)) {
		m_account = account;
		accept();
	}
	else {
		QMessageBox::critical(this , "Error" , "Login failed");
	}
}
