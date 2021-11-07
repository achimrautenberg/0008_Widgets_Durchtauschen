#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QJsonObject>
#include <QList>

/**
 * Die Objektklasse Account.
 * Ein Account ist ein Mitarbeiter der Firma, der sich am Tiny CM einloggen darf.
 *
 * @date 2021-03-23
 * @author Achim Rautenberg
 */

class Account {

private:
	/**
	 * @brief Der Benutzername
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	QString m_sUsername;

	/**
	 * @brief Das Passwort mit der Account abgesichert ist.
	 * Der Account ist zur Zeit noch Klartext.
	 * TODO: Account "verschlüsseln"
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	QString m_sPassword;

public:
	/**
	 * Standardkonstruktor
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	Account();

	/**
	 * Copy Constructor
	 *	@date 2021-04-01
	 * @author Achim Rautenberg
	 */
	Account(const Account & n);

	Account & operator=(const Account & n);

	void set(const Account & n);

	/**
	 * Legt den Benutzernamen fest
	 * @param sUsername: Der Benutzername, den der Account annehmen soll.
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	void setUsername(const QString & sUsername);

	/**
	 * Der Benutzername des Accounts
	 * @return der Benutzername
	 */
	const QString & username() const;

	/**
	 * Legt das Passwort für den Benutzernamen fest.
	 * @param das Passwort
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	void setPassword(const QString & sPassword);

	/**
	 * Gibt das Passwort für den Account zurück
	 * @return das Passwort (in Klartext)
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	const QString & password() const;


	/**
	 * @brief Erstellt eine Kopie dieses Objekts im JSON Format
	 * @return Die JSON Repräsentation dieses Objekts
	 *
	 * @date 2021-03-25
	 * @author Achim Rautenberg
	 */
	QJsonObject toJson() const;

	/**
	 * erstellt aus einem Json einen Account
	 * @date 2021-04-01
	 * @author Achim Rautenberg
	 */
	static Account fromJson(const QJsonObject & oAccount);

	/**
	 * @brief Läd eine Liste von Accounts aus einem QJsonArray heraus
	 * @date 2021-04-01
	 * @author Achim Rautenberg
	 */
	static QList<Account> fromJson(const QJsonArray & arrAccounts);

	/**
	 * Läd aus einer Datei von der Festplatte eine Liste mit Accounts
	 * @param sFilename der Dateiname inkl. Pfad zur Datei, die geladen werden soll.
	 * @return Liste mit Accounts
	 * @date 2021-04-01
	 * @author Achim Rautenberg
	 */
	static QList<Account> fromJsonFile(const QString & sFilename);

	/**
	 * @brief Wandelt dieses Objekt in JSON um und speichert das dann unter dem gegebenen Dateinamen
	 * @param Der Dateiname wo das Objekt gespeichert werden soll.
	 * @return true, wenn Speichern erfolgreich, false wenn nicht.
	 *
	 * @date 2021-03-25
	 * @author Achim Rautenberg
	 */
	bool saveAs(const QString & sFilename);

	/**
	 * @brief Läd einen Account aus einer JSON Datei
	 * @param Der Dateiname (inklusive Pfad) wo die Datei, die geladen werden soll, steht
	 * @return true wenn Laden erfolgreich, fals wenn nicht.
	 * @date 2021-03-26
	 * @author Achim Rautenberg
	 */
	bool load(const QString & sFilename);
};

#endif // ACCOUNT_H
