#include "Prototype.h"

namespace DesignPrototype {
	Prototype::Prototype() {}

	Prototype::~Prototype() {}

	PrototypeA::PrototypeA() {}

	PrototypeA::PrototypeA(const PrototypeA* p) {}

	PrototypeA::~PrototypeA() {}

	Prototype* PrototypeA::Clone() const {
		return new PrototypeA(*this);
	}
}