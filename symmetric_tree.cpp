#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <class T>
struct node{
	T value;
	node* lchild, *rchild;
	node(T v) : value(v), lchild(nullptr), rchild(nullptr)	{}
};

template <class T>
class BTRee{
	node<T> *head;
	public:
		BTRee() : head(nullptr) {}
		
		void create(vector<T>& array)
		{
			int index = 0;
			__create(head, array, index);
		}
		void preorder()
		{
			__preorder(head);
			cout << endl;
		}
		void preorder_NR()
		{
			if (head == nullptr) return;
			stack<node<T>*> s;
			node<T>* tmp;
			s.push(head);
			while (!s.empty()) {
				tmp = s.top(), s.pop();
				cout << tmp->value << " ";
				if (tmp->rchild) s.push(tmp->rchild);
				if (tmp->lchild) s.push(tmp->lchild);
			}
			cout << endl;
		}
		void preorder_NR2()
		{
			stack<node<T>*> s;
			node<T>* tmp = head;
			while (!s.empty() || tmp) {// stack is not empty or tmp is not null
				while (tmp) {
					cout << tmp->value << " ";
					s.push(tmp);
					tmp = tmp->lchild;
				}
				tmp = s.top(), s.pop();
				tmp = tmp->rchild;
			}
			cout << endl;
		}
		
		bool is_symmetric()
		{
			if (head == nullptr) return true;
			return __is_symetric(head->lchild, head->rchild);
		}
	private:
		void __create(node<T>*& head, vector<T>& array, int& index);
		void __preorder(node<T>* head)
		{
			if (head == nullptr) return;
			cout << head->value << " ";
			__preorder(head->lchild);
			__preorder(head->rchild);
		}
		bool __is_symetric(node<T>* lchild, node<T>* rchild)
		{
			if (lchild == nullptr && rchild == nullptr) return true;
			if (lchild != nullptr && rchild != nullptr) {
				if (lchild->value != rchild->value) return false;
				return __is_symetric(lchild->lchild, rchild->rchild) && __is_symetric(lchild->rchild, rchild->lchild);
			} else {
				return false;
			}
		}
};

template <class T>
void BTRee<T>::__create(node<T>*& head, vector<T>& array, int& index)
{
	if (array[index] == 0 || array[index] == '#') {
		return;
	} else {
		head = new node(array[index]);
		__create(head->lchild, array, ++index);
		__create(head->rchild, array, ++index);
	}
}


int main()
{
	BTRee<int> tree;
	vector<int> array{1, 2, 3, 0, 0, 4, 0, 0, 2, 4, 0, 0, 3, 0, 0};;
	tree.create(array);	
	tree.preorder();
	tree.preorder_NR();
	tree.preorder_NR2();
	cout << tree.is_symmetric();
	return 0;
}