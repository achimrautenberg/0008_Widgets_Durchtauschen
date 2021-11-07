#include "common.h"

Account Common::m_account;


void Common::setAccount(const Account & acc) {
	m_account = acc;
}

Account & Common::account() {
	return m_account;
}
