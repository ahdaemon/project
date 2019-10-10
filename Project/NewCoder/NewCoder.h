#ifndef NEW_CODER_H
#define NEW_CODER_H

#include <cstring>
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;
// 牛客网题库。。。https://www.nowcoder.com

namespace NewCoder {

	/************************************************************************
	void test1()
	{
		char string[10];
		char* str1 = "0123456789";
		strcpy(string, str1);
		cout << string << endl;
	}
	************************************************************************/
	void test1()
	{
		char string[11]; // 1、str1的大小为11个字节，还有一个结束符
		const char* str1 = "0123456789"; // 2、字符串常量默认类型为const char* 类型转换为char* 会编译错误
		strcpy(string, str1);
		cout << string << endl;
	}

	/************************************************************************
	void test2()
	{
		char string[10], str1[10];
		int i;
		for(i=0; i<10; i++)
		{
			str1  = 'a';
		}
		strcpy( string, str1 );
	}
	************************************************************************/
	void test2()
	{
		char string[10], str1[10];
		int i;
		for (i = 0; i < 9; i++) // 1、最后一个位置要放结束符
		{
			str1[i] = 'a'; // 2、str1是const char*类型的右值，不能直接赋值
		}
		str1[9] = '\0'; // 3、填充字符串结束符，防止内存的非法越界
		strcpy(string, str1);
		cout << string << endl;
	}

	/************************************************************************
	void test3(char* str1)
	{
		if(str1 == NULL){
			return ;
		}
		char string[10];
		if( strlen( str1 ) <= 10 )
		{
			strcpy( string, str1 );
		}
	}
	************************************************************************/
	void test3(char* str1)
	{
		if (str1 == NULL) {
			return;
		}
		char string[10];
		if (strlen(str1) < 10) // 1、这里改为<号，留出最后一个位置存放结束符'\0'
		{
			strcpy(string, str1);
		}
		cout << string << endl;
	}

	/************************************************************************
	编写一个标准strcpy函数
	************************************************************************/
	char* MyStrcpy(char* dst, const char* src) {
		assert((dst != NULL) && (src != NULL));
		char* str = dst;
		while ((*dst++ = *src++) != '\0');
		return str;
	}

	/************************************************************************
	void GetMemory( char *p )
	{
		p = (char *) malloc( 100 );
	}
	void Test( void )
	{
		char *str = NULL;
		GetMemory( str );
		strcpy( str, "hello world" );
		printf( str );
	}
	************************************************************************/
	void GetMemory(char ** p) // 1、这里形参采用的值传递，内部的修改不会影响到参数，改为 址传递或者引用传递
	{
		*p = (char *)malloc(100);
	}
	void Test(void)
	{
		char *str = NULL;
		GetMemory(&str);
		strcpy(str, "hello world");
		printf(str);
		free(str); str = NULL;
		// 2、使用完堆内存，切记释放，避免造成内存泄漏问题
	}

	/************************************************************************
	char *GetMemory( void )
	{
		char p[] = "hello world";
		return p;
	}
	void Test( void )
	{
		char *str = NULL;
		str = GetMemory();
		printf( str );
	}
	************************************************************************/
	char* GetMemory1(void)
	{
		static char p[] = "hello world"; // 1、局部变量返回后会释放，这里可以设置为静态局部变量使得局部变量的生命周期延长
		return p;
	}
	void Test1(void)
	{
		char *str = NULL;
		str = GetMemory1();
		printf(str);
	}

	/************************************************************************
	void GetMemory( char **p, int num )
	{
		*p = (char *) malloc( num );
	}
	void Test( void )
	{
		char *str = NULL;
		GetMemory( &str, 100 );
		strcpy( str, "hello" );
		printf( str );
	}
	************************************************************************/
	void GetMemory2(char **p, int num)
	{
		assert(num > 0); // 1、入参检查
		*p = (char *)malloc(num);
		assert(*p != NULL); // 2、堆内存申请检查
	}
	void Test2(void)
	{
		char *str = NULL;
		GetMemory2(&str, 100);
		strcpy(str, "hello");
		printf(str);
		free(str); str = NULL;// 3、堆内存释放
	}

	/************************************************************************
	void Test( void )
	{
		char *str = (char *) malloc( 100 );
		strcpy( str, "hello" );
		free( str );
		... //省略的其它语句
	}
	************************************************************************/
	void Test3(void)
	{
		char *str = (char *)malloc(100);
		assert(str != NULL); // 1、内存申请是否成功
		strcpy(str, "hello");
		free(str);
		str = NULL; // 2、赋空，避免野指针
		//省略的其它语句
	}

	/************************************************************************
	编写一个函数，作用是把一个char组成的字符串循环右移n个。比如原来是“abcdefghi”如果n=2，移位后应该是“hiabcdefg” 函数头是这样的：
	pStr是指向以'\0'结尾的字符串的指针
	steps是要求移动的n
	void LoopMove ( char * pStr, int steps )
	{
	 //请填充...
	}
	************************************************************************/
	void LoopMove(char * pStr, int steps)
	{
		assert(pStr != NULL);
		int len = strlen(pStr);
		steps %= len;
		if (steps == 0) {
			return;
		}
		char* tmp = (char*)malloc(len * 2);
		strcpy(tmp, pStr + len - steps);
		strcpy(tmp + steps, pStr);
		*(tmp + len) = '\0';
		strcpy(pStr, tmp);
		free(tmp); tmp = NULL;
	}

	/************************************************************************
		编写类String的构造函数、析构函数和赋值函数，已知类String的原型为
	class String
	{
	public:
		String(const char *str = NULL); // 普通构造函数
		String(const String &other); // 拷贝构造函数
		~ String(void); // 析构函数
		String & operator =(const String &other); // 赋值函数
	private:
		char *m_data; // 用于保存字符串
	};
	************************************************************************/
	class String
	{
	public:
		char *m_data; // 用于保存字符串

	public:
		String(const char *str = NULL) { // 普通构造函数
			if (str == NULL) {
				m_data = new char[1];
				m_data[0] = '\0';
				return;
			}
			int len = strlen(str);
			m_data = new char[len + 1];
			strcpy(m_data, str);
		} 
		String(const String &other) { // 拷贝构造函数
			int len = strlen(other.m_data);
			m_data = new char[len + 1];
			strcpy(m_data, other.m_data);
		} 
		~String(void) { //  析构函数
			if (m_data != NULL) {
				delete[] m_data;
				m_data = NULL;
			}
		}
		String & operator =(const String &other) { // 赋值函数
			if (this == &other) {
				return *this;
			}
			delete[] m_data;
			int len = strlen(other.m_data);
			m_data = new char[len + 1];
			strcpy(m_data, other.m_data);
			return *this;
		}
	};

	/************************************************************************
	请写一个C函数，若处理器是Big_endian的，则返回0；若是Little_endian的，则返回1
	************************************************************************/
	int Endian() {
		union MyUnion
		{
			int a;
			char b;
		};
		MyUnion mu;
		mu.a = 1;
		cout << (int)mu.b << endl;
		return mu.b;
	}

	/************************************************************************
	两个栈实现一个队列
	************************************************************************/
	class MyQueue {
	private:
		stack<int> m_stack1;
		stack<int> m_stack2;

	public:
		void Push(int v) {
			m_stack1.push(v);
		}

		int Pop() {
			if (!m_stack2.empty()) {
				int v = m_stack2.top();
				m_stack2.pop();
				return v;
			}
			else {
				while (!m_stack1.empty()) {
					int v = m_stack1.top();
					m_stack1.pop();
					m_stack2.push(v);
				}
			}
			return Pop();
		}
	};

	/************************************************************************
	实现atoi函数
	************************************************************************/
	int MyAtoi(const char* str) {
		if (str == NULL) {
			return 0;
		}

		int ret = 0, sign = 1;
		while (isspace(*str) == 1) {
			str++;
		}
		if (*str == '-') {
			sign = -1;
		}
		if (*str == '-' || *str == '+') {
			str++;
		}
		while (isdigit(*str)) {
			ret = ret * 10 + *str - '0';
			str++;
		}
		ret *= sign;
		return ret;
	}

	/************************************************************************
	实现itoa函数
	************************************************************************/
	
	void MyStrReverse(char* str) { // 字符串翻转函数
		if (str == NULL) {
			return;
		}

		int len = strlen(str);
		char* p = str, *q = str + len - 1;
		while (p < q) {
			char c = *p;
			*p = *q;
			*q = c;
			p++;
			q--;
		}
	}

	char* MyItoa(int v) {
		static char str[100];
		int i = 0;
		bool sign = v < 0;
		v = abs(v);
		while (v > 0)
		{
			str[i++] = v % 10 + '0';
			v /= 10;
		}
		if (sign) {
			str[i++] = '-';
		}
		str[i] = '\0';
		MyStrReverse(str);
		return str;
	}

	/************************************************************************
	最长公共连续子序列 longgest common sequence LCS，使用到了动态规划的思想
	************************************************************************/
	int MyLCS(string & str1, string &str2)
	{
		int len1 = str1.length();
		int len2 = str2.length();
		vector<vector<int>>dp(len1, vector<int>(len2, 0));
		for (int i = 0; i < len1; i++) {
			dp[i][0] = str1[i] == str2[0] ? 1 : 0;
		}
		for (int j = 0; j < len2; j++) {
			dp[0][j] = str1[0] == str2[j] ? 1 : 0;
		}
		for (int i = 1; i < len1; i++) {
			for (int j = 1; j < len2; j++) {
				if (str1[i] == str2[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
			}
		}
		int longest = 0;
		int longest_index = 0;
		for (int i = 0; i < len1; i++) {
			for (int j = 0; j < len2; j++) {
				if (longest < dp[i][j]) {
					longest = dp[i][j];
					longest_index = i;
				}
			}
		}
		//字符串为从第i个开始往前数longest个
		for (int i = longest_index - longest + 1; i <= longest_index; i++) {
			cout << str1[i];
		}
		cout << endl;
		return longest;
	}

	/************************************************************************
	求字符串最长回文子串
	************************************************************************/
	int LongestPalindromicSubstring(string & a)
	{
		int len = a.length();
		vector<vector<int>>dp(len, vector<int>(len, 0));
		for (int i = 0; i < len; i++) {
			dp[i][i] = 1;
		}
		int max_len = 1;
		int start_index = 0; // abaaba
		for (int i = len - 2; i >= 0; i--) {
			for (int j = i + 1; j < len; j++) {
				if (a[i] == a[j]) {
					if (j - i == 1) {
						dp[i][j] = 2;
					}
					else {
						if (j - i > 1) {
							dp[i][j] = dp[i + 1][j - 1] + 2;
						}
					}
					if (max_len < dp[i][j]) {
						max_len = dp[i][j];
						start_index = i;
					}
				}
				else {
					dp[i][j] = 0;
				}
			}
		}
		cout << "max len is " << max_len << endl;
		cout << "star index is" << start_index << endl;
		return max_len;
	}

	/************************************************************************
	如何合并两个有序链表
	************************************************************************/
	struct MyNode {
		int value;
		MyNode* next;
	};
	MyNode* MyListMerge(MyNode* lhs, MyNode* rhs) {
		if (lhs == NULL) {
			return rhs;
		}
		if (rhs == NULL) {
			return lhs;
		}
		if (lhs->value < rhs->value) {
			lhs->next = MyListMerge(lhs->next, rhs);
			return lhs;
		}
		else {
			rhs->next = MyListMerge(lhs, rhs->next);
			return rhs;
		}
	}

	/************************************************************************
	反转链表 a->b->c c->b->a
	************************************************************************/
	MyNode* MyListReverse(MyNode* node) {
		if (node == NULL) {
			return NULL;
		}
		MyNode* p = node;
		MyNode* cur = node->next;
		p->next = NULL;
		while (cur != NULL) {
			MyNode* q = cur->next;
			cur->next = p;
			p = cur;
			cur = q;
		}
		return p;
	}

	/************************************************************************
	判断一个链表是否为回文链表，说出你的思路并手写代码
	使用栈存储链表前半部分，然后一个个出栈，与后半部分元素比较，如果链表长度未知，
	可以使用快慢指针的方法，将慢指针指向的元素入栈，然后如果快指针指向了链表尾部，
	此时慢指针指向了链表中间
	************************************************************************/
	bool IsPalindromicList(MyNode *a_list)
	{
		if (a_list == nullptr)
		{
			return false;
		}
		stack<int>list_value;
		MyNode * fast = a_list;
		MyNode *slow = a_list;
		while (fast->next != nullptr && fast->next->next != nullptr)
		{
			list_value.push(slow->next->value);
			slow = slow->next;
			fast = fast->next->next;
		}
		cout << "middle elem value is " << slow->next->value << endl;
		if (fast->next != nullptr)
		{
			cout << "the list has odd num of node" << endl;
			slow = slow->next;
		}
		int cur_value;
		while (!list_value.empty())
		{
			cur_value = list_value.top();
			cout << "stack top value is" << cur_value << endl;
			cout << "list value is " << slow->next->value << endl;
			if (cur_value != slow->next->value)
			{
				return false;
			}
			list_value.pop();
			slow = slow->next;
		}
		return true;
	}
}

#endif // NEW_CODER_H