#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <class T>
struct node{
	T value;
	node *lchild, *rchild;
	node(T v):value(v), lchild(nullptr), rchild(nullptr) {}
};

template <class T>
class BST{
	node<T> *root;
	public:
		BST():root(nullptr) {}
		void insert(T value)
		{
			root = __insert(root, value);
		}
		
		node<T>* find(T value)
		{
			return __find(root, value);
		}
		
		void delete_node(T value)
		{
			root = __delete_node(root, value);
		}
		
		void inorder()
		{
			stack<node<T>*> s;
			node<T>* tmp = root;
			while (!s.empty() || tmp) {
				while (tmp) {
					s.push(tmp);
					tmp = tmp->lchild;
				}
				tmp = s.top(), s.pop();
				cout << tmp->value << " ";
				tmp = tmp->rchild;
			}
			cout << endl;
		}
	private:
		node<T>* __insert(node<T>* root, T value)
		{
			if (root == nullptr) {
				root = new node(value);
				return root;
			}
			if (root->value < value) {
				root->rchild = __insert(root->rchild, value);
			} else if (root->value > value) {
				root->lchild = __insert(root->lchild, value);
			}
			return root;
		}
		
		node<T>* __find(node<T>* root, T value)
		{
			if (root == nullptr) return nullptr;
			if (root->value == value) return root;
			if (root->value > value) return find(root->lchild, value);
			else return find(root->rchild, value);
		}
		
		node<T>* p;
		
		node<T>* __delete_node(node<T>* root, T value)
		{
			if (root == nullptr) return nullptr;
			if (root->value == value) {
				if (root->lchild == nullptr && root->rchild == nullptr) {
					delete root;
					return nullptr;
				} else if (root->lchild != nullptr && root->rchild != nullptr) {
					p = root->lchild;
					while (p->rchild) {
						p = p->rchild;
					}
					T tmp = p->value;
					p->value = root->value;
					root->value = tmp;
					root->lchild = __delete_node(root->lchild, value);
				} else if (root->lchild != nullptr) {
					p = root;
					root = root->lchild;
					delete p;
				} else {
					p = root;
					root = root->rchild;
					delete p;
				}
			} else if (root->value < value) {
				root->rchild = __delete_node(root->rchild, value);
			} else {
				root->lchild = __delete_node(root->lchild, value);
			}
			return root;
		}
};

int main()
{
	BST<int> obj;
	int array[] = {333, 532, 1, 4, 3, 2, 98, 7};
	int i;
	for(i = 0; i < 8; i++)
		obj.insert(array[i]);
	obj.inorder();
	std::cout << "\n";
	obj.delete_node(333);
	obj.delete_node(4);
	obj.delete_node(98);
	obj.inorder();
	return 0;
}