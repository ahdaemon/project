#include "Observer.h"

namespace DesignObserver {
	void Subject::Attach(Observer* obv) {
		if (obv != NULL) {
			m_obvs.push_back(obv);
		}
	}

	void Subject::Detach(Observer* obv) {
		if (obv != NULL) {
			m_obvs.remove(obv);
		}
	}

	void Subject::Notify() {
		for (auto& obv : m_obvs) {
			obv->Update();
		}
	}

	void Subject::SetState(const string& state) {
		m_state = state;
	}

	string Subject::GetState() {
		return m_state;
	}
}