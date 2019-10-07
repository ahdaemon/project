#ifndef PROXY_H
#define PROXY_H

namespace DesignProxy {
	class Test {
	public:
		virtual void Operation() = 0;
	};

	class Test1 : public Test {
	public:
		void Operation() {}
	};

	class Proxy {
	private:
		Test* m_t;

	public:
		Proxy(Test* t);
		~Proxy();

		void Operation();
	};
}

#endif // PROXY_H