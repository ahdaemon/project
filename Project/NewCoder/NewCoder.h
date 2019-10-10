#ifndef NEW_CODER_H
#define NEW_CODER_H

#include <cstring>
#include <iostream>
#include <cassert>
#include <stack>
#include <vector>
using namespace std;
// ţ������⡣����https://www.nowcoder.com

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
		char string[11]; // 1��str1�Ĵ�СΪ11���ֽڣ�����һ��������
		const char* str1 = "0123456789"; // 2���ַ�������Ĭ������Ϊconst char* ����ת��Ϊchar* ��������
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
		for (i = 0; i < 9; i++) // 1�����һ��λ��Ҫ�Ž�����
		{
			str1[i] = 'a'; // 2��str1��const char*���͵���ֵ������ֱ�Ӹ�ֵ
		}
		str1[9] = '\0'; // 3������ַ�������������ֹ�ڴ�ķǷ�Խ��
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
		if (strlen(str1) < 10) // 1�������Ϊ<�ţ��������һ��λ�ô�Ž�����'\0'
		{
			strcpy(string, str1);
		}
		cout << string << endl;
	}

	/************************************************************************
	��дһ����׼strcpy����
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
	void GetMemory(char ** p) // 1�������ββ��õ�ֵ���ݣ��ڲ����޸Ĳ���Ӱ�쵽��������Ϊ ַ���ݻ������ô���
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
		// 2��ʹ������ڴ棬�м��ͷţ���������ڴ�й©����
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
		static char p[] = "hello world"; // 1���ֲ��������غ���ͷţ������������Ϊ��̬�ֲ�����ʹ�þֲ����������������ӳ�
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
		assert(num > 0); // 1����μ��
		*p = (char *)malloc(num);
		assert(*p != NULL); // 2�����ڴ�������
	}
	void Test2(void)
	{
		char *str = NULL;
		GetMemory2(&str, 100);
		strcpy(str, "hello");
		printf(str);
		free(str); str = NULL;// 3�����ڴ��ͷ�
	}

	/************************************************************************
	void Test( void )
	{
		char *str = (char *) malloc( 100 );
		strcpy( str, "hello" );
		free( str );
		... //ʡ�Ե��������
	}
	************************************************************************/
	void Test3(void)
	{
		char *str = (char *)malloc(100);
		assert(str != NULL); // 1���ڴ������Ƿ�ɹ�
		strcpy(str, "hello");
		free(str);
		str = NULL; // 2�����գ�����Ұָ��
		//ʡ�Ե��������
	}

	/************************************************************************
	��дһ�������������ǰ�һ��char��ɵ��ַ���ѭ������n��������ԭ���ǡ�abcdefghi�����n=2����λ��Ӧ���ǡ�hiabcdefg�� ����ͷ�������ģ�
	pStr��ָ����'\0'��β���ַ�����ָ��
	steps��Ҫ���ƶ���n
	void LoopMove ( char * pStr, int steps )
	{
	 //�����...
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
		��д��String�Ĺ��캯�������������͸�ֵ��������֪��String��ԭ��Ϊ
	class String
	{
	public:
		String(const char *str = NULL); // ��ͨ���캯��
		String(const String &other); // �������캯��
		~ String(void); // ��������
		String & operator =(const String &other); // ��ֵ����
	private:
		char *m_data; // ���ڱ����ַ���
	};
	************************************************************************/
	class String
	{
	public:
		char *m_data; // ���ڱ����ַ���

	public:
		String(const char *str = NULL) { // ��ͨ���캯��
			if (str == NULL) {
				m_data = new char[1];
				m_data[0] = '\0';
				return;
			}
			int len = strlen(str);
			m_data = new char[len + 1];
			strcpy(m_data, str);
		} 
		String(const String &other) { // �������캯��
			int len = strlen(other.m_data);
			m_data = new char[len + 1];
			strcpy(m_data, other.m_data);
		} 
		~String(void) { //  ��������
			if (m_data != NULL) {
				delete[] m_data;
				m_data = NULL;
			}
		}
		String & operator =(const String &other) { // ��ֵ����
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
	��дһ��C����������������Big_endian�ģ��򷵻�0������Little_endian�ģ��򷵻�1
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
	����ջʵ��һ������
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
	ʵ��atoi����
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
	ʵ��itoa����
	************************************************************************/
	
	void MyStrReverse(char* str) { // �ַ�����ת����
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
	��������������� longgest common sequence LCS��ʹ�õ��˶�̬�滮��˼��
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
		//�ַ���Ϊ�ӵ�i����ʼ��ǰ��longest��
		for (int i = longest_index - longest + 1; i <= longest_index; i++) {
			cout << str1[i];
		}
		cout << endl;
		return longest;
	}

	/************************************************************************
	���ַ���������Ӵ�
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
	��κϲ�������������
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
	��ת���� a->b->c c->b->a
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
	�ж�һ�������Ƿ�Ϊ��������˵�����˼·����д����
	ʹ��ջ�洢����ǰ�벿�֣�Ȼ��һ������ջ�����벿��Ԫ�رȽϣ����������δ֪��
	����ʹ�ÿ���ָ��ķ���������ָ��ָ���Ԫ����ջ��Ȼ�������ָ��ָ��������β����
	��ʱ��ָ��ָ���������м�
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