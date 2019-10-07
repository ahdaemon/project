#ifndef FACTORY_H
#define FACTORY_H

// �򵥹���ģʽ��ʵ�ֵ�����Ĵ����ӿڣ�����ͨ�����ݲ������ƴ�������������

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