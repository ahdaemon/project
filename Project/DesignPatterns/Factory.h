#ifndef FACTORY_H
#define FACTORY_H

// 简单工厂模式，实现单个类的创建接口，可以通过传递参数控制创建的子类类型

namespace DesignFactory {
	class ProductBase {
	public:
		ProductBase();
		virtual ~ProductBase();
	};

	class ProductA : public ProductBase {
	public:
		ProductA();
		~ProductA();
	};

	class FactoryBase {
	public:
		FactoryBase();
		virtual ~FactoryBase();

		virtual ProductBase* CreateProduct() = 0;
	};

	class FactoryA : public FactoryBase {
	public:
		FactoryA();
		~FactoryA();

		ProductBase* CreateProduct();
	};
}

#endif // FACTORY_H