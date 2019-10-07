#ifndef SINGLETON_H
#define SINGLETON_H
#include <iostream>

namespace DesignSingleton {
	template<typename T>
	class Singleton {
	private:
		static Singleton<T>* m_instance;
		Singleton();

	public:
		Singleton<T>* Instance() {
			if (m_instance == NULL) {
				m_instance = new Singleton<T>();
			}
			return m_instance;
		}
	};
}

#endif // SINGLETON_H