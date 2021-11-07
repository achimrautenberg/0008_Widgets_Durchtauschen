#ifndef COMMON_H
#define COMMON_H

#include "Account.h"

/**
 * @brief In der Klasse Common legen wir Daten ab, die wir ganz allgemein global von allen Stellen des Programms
 * aus, im Zugriff haben möchten.
 *
 * @date 2021-03-26
 * @author Achim Rautenberg
 */

class Common {
private:
	/**
	 * @brief Der Account mit dem wir uns eingeloggt haben
	 * @date 2021-03-26
	 * @author Achim Rautenberg
	 */
	static Account m_account;

public:
	/**
	 * @brief legt den Account fest, mit dem wir uns eingeloggt haben
	 * @param Der eingeloggte Account
	 * @date 2021-03-26
	 * @author Achim Rautenberg
	 */
	static void setAccount(const Account & acc);

	/**
	 * @brief Gibt den eingeloggten Account zurück.
	 * @return der eingeloggte Account
	 * @date 2021-03-26
	 * @author Achim Rautenberg
	 */
	static Account & account();
};



#endif // COMMON_H
