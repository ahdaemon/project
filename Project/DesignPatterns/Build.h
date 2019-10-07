#ifndef BUILD_H
#define BUILD_H
#include <string>
using namespace std;

// Builder 模式强调的是一步步创建对象，并通过相同的创建过程可以获得不同的结果对象

namespace DesignBuild {
	class ProductBase {
	public:
		ProductBase();
		~ProductBase();
	};

	class ProductA : public ProductBase {
	public:
		ProductA();
		~ProductA();
	};

	class Builder {
	public:
		Builder();
		~Builder();

		virtual void BuildPartA(const string& para) = 0;
		virtual void BuildPartB(const string& para) = 0;

		virtual ProductBase* GetProduct() = 0;
	};

	class BuilderA : public Builder {
	public:
		BuilderA();
		~BuilderA();

		virtual void BuildPartA(const string& para);
		virtual void BuildPartB(const string& para);

		virtual ProductBase* GetProduct();
	};

	class Dirctor {
	public:
		Dirctor(Builder* builder);
		~Dirctor();

		void Construct();

	private:
		Builder* m_builder;
	};

// 使用方式
// 	BuilderA* builder = new BuilderA();
// 	Dirctor* dirctor = new Dirctor(builder);
// 	dirctor->Construct();
}

#endif // BUILD_H