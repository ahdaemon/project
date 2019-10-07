#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

// ���󹤳���
// AbstractFactory ģʽ��Ϊ����һ�飨�ж��ࣩ��ػ������Ķ����ṩ�����ӿڣ��� Factory ģʽ��Ϊһ������ṩ�����ӿڻ��ӳٶ���Ĵ�����������ʵ��

namespace DesignAbsFactory {
	class ProductBaseA {
	public:
		ProductBaseA();
		virtual ~ProductBaseA();
	};

	class ProductA1 : public ProductBaseA {
	public:
		ProductA1();
		~ProductA1();
	};

	class ProductA2 : public ProductBaseA {
	public:
		ProductA2();
		~ProductA2();
	};

	class ProductBaseB {
	public:
		ProductBaseB();
		virtual ~ProductBaseB();
	};

	class ProductB1 : public ProductBaseB {
	public:
		ProductB1();
		~ProductB1();
	};

	class ProductB2 : public ProductBaseB {
	public:
		ProductB2();
		~ProductB2();
	};

	class FactoryBase {
	public:
		FactoryBase();
		virtual ~FactoryBase();

		virtual ProductBaseA* CreateProductA() = 0;
		virtual ProductBaseB* CreateProductB() = 0;
	};

	class Factory1 : public FactoryBase {
	public:
		Factory1();
		~Factory1();

		ProductBaseA* CreateProductA();
		ProductBaseB* CreateProductB();
	};

	class Factory2 : public FactoryBase {
	public:
		Factory2();
		~Factory2();

		ProductBaseA* CreateProductA();
		ProductBaseB* CreateProductB();
	};
}

#endif // ABSTRACT_FACTORY_H