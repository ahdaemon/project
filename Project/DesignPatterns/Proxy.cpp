#include "Proxy.h"

namespace DesignProxy {
	Proxy::Proxy(Test* t) {
		m_t = t;
	}

	Proxy::~Proxy() {
	
	}

	void Proxy::Operation() {
		m_t->Operation();
	}
}
