#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct node{
	T value;
	node *lchild, *rchild;
	node(T v) : value(v), lchild(nullptr), rchild(nullptr) {}
};

template <class T>
class BTRee{
	private:
		node<T> *head;
	public:
		BTRee() : head(nullptr) {}
		
		void create_dynamic()
		{
			__create_dynamic(head);
		}
		
		void create_static(vector<T>& array)
		{
			int index = 0;
			__create_static(head, array, index);
		}
		
		void preorder()
		{
			__preorder(head);
			cout << endl;
		}
		
		int pathsum(int sum)
		{
			int count = 0;
			__pathsum(head, sum, count);
			return count;
		}
	private:
		void __pathsum(node<T>* head, int sum, int& count);
		void __create_dynamic(node<T>* &head);
		void __create_static(node<T>* &head, vector<T>& array, int& index);
		void __preorder(node<T>* head);
		void __pathsum_start_with_root(node<T>*head, int sum, int& count);
};

template <class T>
void BTRee<T>::__pathsum(node<T>* head, int sum, int& count)
{
	if (head == nullptr) return;
	__pathsum_start_with_root(head, sum, count);
	__pathsum(head->lchild, sum, count);
	__pathsum(head->rchild, sum, count);
}

template <class T>
void BTRee<T>::__pathsum_start_with_root(node<T>*head, int sum, int& count)
{
	if (head == nullptr) return;
	if (head->value == sum) ++count;
	__pathsum_start_with_root(head->lchild, sum - head->value, count);
	__pathsum_start_with_root(head->rchild, sum - head->value, count);
}
template <class T>
void BTRee<T>::__create_dynamic(node<T>* &head)
{
	T tmp;
	cin >> tmp;
	if (tmp == 0 || tmp == '#') {
		return;
	} else {
		head = new node<T>(tmp);
		__create(head->lchild);
		__create(head->rchild);
	}	
}

template <class T>
void BTRee<T>::__create_static(node<T>* &head, vector<T>& array, int& index)
{
	if (array[index] == 0 || array[index] == '#') {
		return;
	} else {
		head = new node(array[index]);
		__create_static(head->lchild, array, ++index);
		__create_static(head->rchild, array, ++index);
	}
}

template <class T>
void BTRee<T>::__preorder(node<T>* head)
{
	if (head == nullptr) return;
	cout << head->value << " ";
	__preorder(head->lchild);
	__preorder(head->rchild);
}

int main()
{
	BTRee<int> btree;
	vector<int> array{10, 5, 3, 3, 0, 0, -2, 0, 0, 2, 0, 1, 0, 0, -3, 0, 11, 0, 0};
	btree.create_static(array);
	btree.preorder();
	cout << btree.pathsum(8) << endl;
	return 0;
}