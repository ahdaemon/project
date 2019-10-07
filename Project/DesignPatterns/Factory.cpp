#include "Factory.h"
#include <iostream>
using namespace std;

namespace DesignFactory {
	ProductBase::ProductBase() {
	
	}

	ProductBase::~ProductBase() {
	
	}

	ProductA::ProductA() : ProductBase() {
		cout << "construct productA" << endl;
	}

	ProductA::~ProductA() {
	
	}

	FactoryBase::FactoryBase() {
	
	}

	FactoryBase::~FactoryBase() {
	
	}

	FactoryA::FactoryA() : FactoryBase() {
		cout << "construct factoryA" << endl;
	}

	FactoryA::~FactoryA() {
	
	}
	
	ProductBase* FactoryA::CreateProduct() {
		return new ProductA();
	}
}