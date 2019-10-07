#ifndef BRIDGE_H
#define BRIDGE_H

// ʲô���Ž��أ����������ֵģ��Ǿ�����ί�еĵط���AbstractionImp* _imp;�������ˣ�������ţ�һ����ͨ���ܲ�κ�ʵ�ֲ�ε��š��ɴ�����Ҳ���������ģʽ��ʵ����Ϊ������޶ȵ�ʵ�ִ���Ŀ�������
// 	AbstractionImp* imp = new AbstractionImpA();
// 	Abstraction* abs_ = new AbstractionA(imp);
// 	abs_->Operation();

namespace DesignBridge {
	class AbstractionImp;
	class Abstraction {
	public:
		Abstraction() {}
		~Abstraction() {}

		virtual void Operation() = 0;
	};

	class AbstractionA : public Abstraction {
	private:
		AbstractionImp* m_imp;
	public:
		AbstractionA(AbstractionImp* imp);
		~AbstractionA() {}
		void Operation();
	};

	class AbstractionImp {
	public:
		AbstractionImp() {}
		~AbstractionImp() {}

		virtual void Operation() = 0;
	};

	class AbstractionImpA : public AbstractionImp {
	public:
		AbstractionImpA() {}
		~AbstractionImpA() {}
		void Operation();
	};
}

#endif // BRIDGE_H