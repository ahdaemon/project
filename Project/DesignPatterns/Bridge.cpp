#include "Bridge.h"

namespace DesignBridge {
	AbstractionA::AbstractionA(AbstractionImp* imp) {
		m_imp = imp;
	}

	void AbstractionA::Operation() {
		m_imp->Operation();
	}

	void AbstractionImpA::Operation() {
	
	}
}