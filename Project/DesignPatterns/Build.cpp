#include "Build.h"
#include <iostream>
using namespace std;

namespace DesignBuild {
	ProductBase::ProductBase() {}

	ProductBase::~ProductBase() {}

	ProductA::ProductA() {}

	ProductA::~ProductA() {}

	Builder::Builder() {}

	Builder::~Builder() {}

	BuilderA::BuilderA() {}

	BuilderA::~BuilderA() {}

	void BuilderA::BuildPartA(const string& para) {
		cout << "builderA buildPartA" << endl;
	}

	void BuilderA::BuildPartB(const string& para) {
		cout << "builderA buildPartB" << endl;
	}

	ProductBase* BuilderA::GetProduct() {
		BuildPartA("pre-build");
		BuildPartB("pre-build");
		return new ProductA();
	}

	Dirctor::Dirctor(Builder* builder) {
		m_builder = builder;
	}

	Dirctor::~Dirctor() {}

	void Dirctor::Construct() {
		m_builder->BuildPartA("user-para");
		m_builder->BuildPartB("user_para");
	}
}