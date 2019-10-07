#include "AbstractFactory.h"
#include <iostream>
using namespace std;

namespace DesignAbsFactory {
	ProductBaseA::ProductBaseA() {}

	ProductBaseA::~ProductBaseA() {}

	ProductA1::ProductA1() {
		cout << "construct productA1" << endl;
	}

	ProductA1::~ProductA1() {}

	ProductA2::ProductA2() {
		cout << "construct productA2" << endl;
	}

	ProductA2::~ProductA2() {}

	ProductBaseB::ProductBaseB() {}

	ProductBaseB::~ProductBaseB() {}

	ProductB1::ProductB1() {
		cout << "construct productB1" << endl;
	}

	ProductB1::~ProductB1() {}

	ProductB2::ProductB2() {
		cout << "construct productB2" << endl;
	}

	ProductB2::~ProductB2() {}

	FactoryBase::FactoryBase() {}

	FactoryBase::~FactoryBase() {}

	Factory1::Factory1() {
		cout << "construct factory1" << endl;
	}

	Factory1::~Factory1() {}

	ProductBaseA* Factory1::CreateProductA() {
		return new ProductA1();
	}

	ProductBaseB* Factory1::CreateProductB() {
		return new ProductB1();
	}

	Factory2::Factory2() {
		cout << "construct factory2" << endl;
	}

	Factory2::~Factory2() {}

	ProductBaseA* Factory2::CreateProductA() {
		return new ProductA2();
	}

	ProductBaseB* Factory2::CreateProductB() {
		return new ProductB2();
	}
}