#ifndef DLG_LOGIN_H
#define DLG_LOGIN_H

/**
 * Der eigentliche Login-Dialog. Mit diesem Dialog kann man sich authentifizieren.
 * Später soll dieser Benutzer dann auch gegenüber dem Server authentifiziert werden.
 *
 * @date 2021-03-21
 * @author Achim Rautenberg
 */

#include <QDialog>
#include "Account.h"

namespace Ui {
	class Dlg_Login;
}

class Dlg_Login : public QDialog
{
	Q_OBJECT

private:
	/**
	 * Die eigentliche UI
	 *
	 * @date 2021-03-2021
	 * @author Achim Rautenberg
	*/
	Ui::Dlg_Login *ui;

	/**
	  Der ausgewählte Account

	  @date 2021-03-25
	  @author Achim Rautenberg
	  */
	Account m_account;

	/**
	  Liste mit möglichen Accounts, die sich anmelden dürfen
	  @date 2021-04-01
	  @author Achim Rautenberg
	  */
	QList<Account> m_lstAccounts;

public:
	/**
	 * Ein einfacher Standard-Konstruktor
	 *
	 * @param parent = MainWindow
	 * @date 2021-03-21
	 */
	explicit Dlg_Login(QWidget *parent = nullptr);

	/**
	  Standard Destruktor

	  @date 2021-03-21
	  @author Achim Rautenberg
	 */
	~Dlg_Login();

	/**
	 * Gibt den aktuell eingestellten Account zurück.
	 * @return aktueller Account
	 *
	 * @date 2021-03-25
	 * @author Achim Rautenberg
	 */
	const Account & account() const;

	/**
	 * Läd die Liste mit Accounts, die sich einloggen dürfen.
	 * @date 2021-04-01
	 * @author Achim Rautenberg
	 */
	void loadAccounts();

	/**
	 * Prüft, ob der übergebene Account in der Liste gültiger Accounts (mit Login Berechtigung)
	 * gefunden wurde.
	 * true: wenn Login erlaubt (gefunden), sonst false
	 * @date 2021-04-01
	 * @author Achim Rautenberg
	 */
	bool isAccountValid(const Account & account);

private slots:
	/**
	 * Wenn der Login-Knopf gedrückt wurde,
	 * dann soll der Benutzer mit Passwort geprüft werden,
	 * und als aktiver Benutzer im System gewählt werden.
	 *
	 * @date 2021-03-21
	 * @author Achim Rautenberg
	 */
	void onBtnLogin();
};

#endif // DLG_LOGIN_H
