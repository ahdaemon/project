#ifndef PROTOTYPE_H
#define PROTOTYPE_H

namespace DesignPrototype {
	class Prototype {
	public:
		Prototype();
		~Prototype();

		virtual Prototype* Clone() const = 0;
	};

	class PrototypeA : public Prototype {
	public:
		PrototypeA();
		PrototypeA(const PrototypeA* p);
		~PrototypeA();

		Prototype* Clone() const;
	};
}

#endif // PROTOTYPE_H