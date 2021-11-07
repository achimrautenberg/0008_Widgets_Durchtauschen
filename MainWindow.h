#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
	Das Hauptfenster von Tiny CM
	@date 2021-03-23
	@author Achim Rautenberg
*/

#include <QMainWindow>
#include "Account.h"
#include "common.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	enum WIDGET {
		eWidget_Accounts,
		eWidget_Player,
		eWidget_Settings,
		eWidget_Plugins,
		eWidget_Licenses
	};

private:
	/**
	 * Das eigentliche UI Objekt
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	Ui::MainWindow * m_pUi;

	/**
	 * Merkt sich, ob der Benutzer bereits eingeloggt wurde.
	 * Diese Variable wird gebraucht, weil der Login Dialog aufpoppt, wenn das Haupfenster angezeigt wird.
	 * Um zu verhindern, dass dieses Fenster aufpoppt, wenn der Benutzer bereits eingeloggt ist, brauchen
	 * wir diese Variable.
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	bool m_bLoggedIn;

	/**
	 * Der gewählte Account
	 *
	 * @date 2021-03-25
	 * @author Achim Rautenberg
	 * @change Der Account wurde aus MainWindow entfernt und befindet sich nun in der Klasse Common
	 * @date 2021-03-26
	 * @author Achim Rautenberg
	 */
	//Account m_account;

public:
	/**
	 * @brief Konstruktor
	 * @param parent <- ist null
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	MainWindow(QWidget *parent = nullptr);

	/**
	  Der Destruktor

	  @date 2021-03-23
	  @author Achim Rautenberg
	  */
	~MainWindow();

	static void switchWidget(const WIDGET & w);

	QWidget * initNewWidget(const WIDGET & w);
	void clearLayout();
	void addNewWidget(QWidget * pW);

protected:
	/**
	 * @brief Dieses Event wird ausgelöst, wenn das Hauptfenster angezeigt wird.
	 * Hier wird dann auch der Login-Dialog angezeigt. Dieser wird aber nur
	 * dann dargestellt, wenn die Membervariable m_bLogged in false ist.
	 * Hat sich der Benutzer erfolgreich eingeloggt, wird die Variable auf true
	 * gestellt und damit verhindert, dass der Login-Dialog erneut aufpoppt.
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	void showEvent(QShowEvent *event);

private slots:
	/**
	 * Dieser Slot wird von der showEvent Funktion aufgerufen. Nachdem das ShowEvent durchgelaufen ist, wird
	 * dieser Slot in die EventQueue eingefügt. Dadurch wird zuerst das Hauptfenster wirklich gezeichnet und dargestellt,
	 * bevor dieser Slot ausgeführt wird. In dieser Funktion wird dann der eigentliche Login Dialog aufgemacht.
	 *
	 * @date 2021-03-23
	 * @author Achim Rautenberg
	 */
	void onShown();


};
#endif // MAINWINDOW_H
