#include "Account.h"
#include <QJsonDocument>
#include <QFile>
#include <QJsonArray>

Account::Account() {
	m_sUsername = "";
	m_sPassword = "";
}

Account::Account(const Account & n) {
	set(n);
}

Account & Account::operator=(const Account & n) {
	set(n);
	return *this;
}

void Account::set(const Account & n) {
	setUsername(n.username());
	setPassword(n.password());
}

void Account::setUsername(const QString & sUsername) {
	m_sUsername = sUsername;
}

const QString & Account::username() const {
	return m_sUsername;
}

void Account::setPassword(const QString & sPassword) {
	m_sPassword = sPassword;
}

const QString & Account::password() const {
	return m_sPassword;
}

QJsonObject Account::toJson() const {
	QJsonObject o;
	o.insert("username" , username());
	o.insert("password" , password());
	return o;
}

Account Account::fromJson(const QJsonObject & oAccount) {
	Account account;
	account.setUsername(oAccount.value("username").toString());
	account.setPassword(oAccount.value("password").toString());
	return account;
}

QList<Account> Account::fromJson(const QJsonArray & arrAccounts) {
	QList<Account> lstAccounts;
	for(int i = 0 ; i < arrAccounts.count() ; i++) {
		QJsonObject oAccount = arrAccounts[i].toObject();
		Account account = Account::fromJson(oAccount);
		lstAccounts << account;
	}
	return lstAccounts;
}

QList<Account> Account::fromJsonFile(const QString & sFilename) {
	QFile file(sFilename);
	file.open(QIODevice::ReadOnly);
	QByteArray baContent = file.readAll();
	file.close();
	QJsonDocument doc = QJsonDocument::fromJson(baContent);
	QJsonArray arrAccounts = doc.array();
	QList<Account> lstAccounts = Account::fromJson(arrAccounts);
	return lstAccounts;
}

bool Account::saveAs(const QString & sFilename) {
	QJsonObject o = toJson();
	QJsonDocument doc;
	doc.setObject(o);
	QByteArray ba = doc.toJson();
	QFile f(sFilename);
	if(!f.open(QIODevice::WriteOnly)) return false;
	f.write(ba);
	f.close();
	return true;
}

bool Account::load(const QString & sFilename) {
	QFile f(sFilename);
	if(!f.open(QFile::ReadOnly)) return false;
	QByteArray ba = f.readAll();
	f.close();
	QJsonDocument doc = QJsonDocument::fromJson(ba);
	QJsonObject o = doc.object();
	fromJson(o);
	return true;
}
