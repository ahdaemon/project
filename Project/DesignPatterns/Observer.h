#ifndef OBSERVER_H
#define OBSERVER_H
// 观察者模式 MVC，struct，mfc等都有使用到此模式，应用非常广
// Observer* obv = new Observer();
// Subject* sub = new Subject();
// sub->Attach(obv);
// sub->Notify();

#include <list>
#include <string>
using namespace std;

namespace DesignObserver {
	class Observer;
	class Subject {
	private:
		list<Observer*> m_obvs;
		string m_state;

	public:
		Subject() {}
		~Subject() {}

		virtual void Attach(Observer* obv);
		virtual void Detach(Observer* obv);
		virtual void Notify();
		virtual void SetState(const string& state);
		virtual string GetState();
	};

	class Observer {
	public:
		Observer() {}
		~Observer() {}

		void Update() {}
	};
}

#endif // OBSERVER_H