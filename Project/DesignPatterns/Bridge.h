#ifndef BRIDGE_H
#define BRIDGE_H

// 什么是桥接呢，在哪里体现的？那就是在委托的地方（AbstractionImp* _imp;）体现了，这就是桥，一座沟通功能层次和实现层次的桥。由此我们也看到，设计模式其实就是为了最大限度的实现代码的可重用性
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