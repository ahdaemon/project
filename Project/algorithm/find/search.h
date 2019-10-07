#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <queue>
using namespace std;

namespace SearchAlgo {
	// ���ֲ��ҷ� �㷨���Ӷ�ΪO(logn)
	// ����ҵ�Ԫ�ص���tar���򷵻���Ӧ������
	// ���û�ҵ����򷵻�-1
	template<typename T>
	int BinarySearch(T arr[], int sz, T tar) {
		int i = 0, j = sz - 1;
		while (i <= j) {
			int mid = i + (j - i) / 2;
			if (arr[mid] == tar) {
				return mid;
			}
			if (arr[mid] > tar) {
				j = mid - 1;
			}
			else {
				i = mid + 1;
			}
		}
		return -1;
	}

	// ���������� BinarySearchTree
	template<typename Key, typename Value>
	class BST {
	private:
		struct Node {
			Key key;
			Value value;
			Node* left;
			Node* right;

			Node(Key k, Value v) {
				key = k;
				value = v;
				left = right = NULL;
			}

			Node(Node* node) {
				key = node->key;
				value = node->value;
				left = node->left;
				right = node->right;
			}
		};

		Node* root;
		int count;

	private:
		Node* insert(Node* node, Key k, Value v) {
			if (node == NULL) {
				count++;
				node = new Node(k, v);
			}

			if (k == node->key) {
				node->value = k;
			}
			else if (k < node->key) {
				node->left = insert(node->left, k, v);
			}
			else {
				node->right = insert(node->right, k, v);
			}

			return node;
		}

		Value* get(Node* node, Key k) {
			if (node == NULL) {
				return NULL;
			}

			if (k == node->key) {
				return &(node->value);
			}
			else if (k < node->key) {
				return get(node->left, k);
			}
			else {
				return get(node->right, k);
			}
		}

		void destory(Node* node) {
			if (node != NULL) {
				destory(node->left);
				destory(node->right);
				delete node;
				count--;
			}
		}

		void preTrave(Node* node) {
			if (node != NULL) {
				cout << node->key << endl;
				preTrave(node->left);
				preTrave(node->right);
			}
		}

		void midTrave(Node* node) {
			if (node != NULL) {
				midTrave(node->left);
				cout << node->key << endl;
				midTrave(node->right);
			}
		}

		void postTrave(Node* node) {
			if (node != NULL) {
				postTrave(node->left);
				postTrave(node->right);
				cout << node->key << endl;
			}
		}

		Node* getMin(Node* node) {
			if (node->left == NULL) {
				return node;
			}
			return getMin(node->left);
		}

		Node* getMax(Node* node) {
			if (node->right == NULL) {
				return node;
			}
			return getMax(node->right);
		}

		Node* removeMin(Node* node) {
			if (node->left == NULL) {
				Node* right = node->right;
				delete node;
				count--;
				return right;
			}
			node->left = RemoveMin(node->left);
			return node;
		}

		Node* removeMax(Node* node) {
			if (node->right == NULL) {
				Node* left = node->left;
				delete node;
				count--;
				return left;
			}
			node->right = removeMax(node->right);
			return node;
		}

		Node* remove(Node* node, Key key) {
			if (node == NULL) {
				return NULL;
			}
			if (key < node->key) {
				node->left = remove(node->left, key);
				return node;
			}
			else if (key > node->key) {
				node->right = remove(node->right, key);
				return node;
			}
			else {
				if (node->left == NULL) {
					Node* right = node->right;
					delete node;
					count--;
					return right;
				}
				if (node->right == NULL) {
					Node* left = node->left;
					delete node;
					count--;
					return left;
				}
				//node->left != NULL && node->right != NULL
				Node* successor = new Node(getMin(node->right));
				count++;
				successor->left = node->left;
				successor->right = removeMin(node->right);
				delete node;
				count--;
				return successor;
			}
		}

	public:
		BST() {
			root = NULL;
			count = 0;
		}

		~BST() {
			destory(root);
		}

		int Size() {
			return count;
		}

		bool Empty() {
			return count == 0;
		}

		void Insert(Key k, Value v) {
			root = insert(root, k, v);
		}

		Value* Get(Key k) {
			return get(root, k);
		}

		void PreTrave() { // ǰ����� �������
			preTrave(root);
		}

		void MidTrave() { // ������� �������
			midTrave(root);
		}

		void PostTrave() { // ������� �������
			postTrave(root);
		}

		void LevelTrave() { // ������� �������
			queue<Node*> q;
			q.push(root);
			while (!q.empty())
			{
				Node* node = q.front();
				q.pop();
				cout << node->key << endl;
				if (node->left != NULL) {
					q.push(node->left);
				}
				if (node->right != NULL) {
					q.push(node->right);
				}
			}
		}

		// ��ȡ��С�ļ�ֵ
		Key GetMin() {
			Node* node = getMin(root);
			return node->key;
		}

		// ��ȡ����key
		Key GetMax() {
			Node* node = getMax(root);
			return node->key;
		}

		// ɾ����С�Ľڵ�
		void RemoveMin() {
			if (root) {
				root = removeMin(root);
			}
		}

		// ɾ�����Ľڵ�
		void RemoveMax() {
			if (root) {
				root = removeMax(root);
			}
		}

		// ɾ������ڵ�
		void Remove(Key key) {
			if (root) {
				root = remove(root, key);
			}
		}
	};

	// RedBlackTree ����� ������ƽ�����ʵĶ��������� 
	// todo
}

#endif // SEARCH_H