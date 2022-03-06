#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <class T>
struct node{
	T value;
	node *lchild, *rchild;
	node(T v): value(v), lchild(nullptr), rchild(nullptr) {}	
};

template <class T>
class BTRee{
	node<T> *root;
	public:
		BTRee() : root(nullptr) {}
		void inorder()
		{
			__inorder(root);
			cout << endl;
		}
		
		void __inorder(node<T>* root)
		{
			if (root == nullptr) return;
			__inorder(root->lchild);
			cout << root->value << " ";
			__inorder(root->rchild);
		}
		
		void create(vector<int>& array)
		{
			stack<node<T>*> s;
			node<T>* tmp;
			int index = 0;
			while (!s.empty() || array[index] != -1) {
				while (array[index] != -1) {
					if (root == nullptr) {
						root = new node(array[index]);
						tmp = root;
						s.push(tmp);
					} else {
						tmp->lchild = new node(array[index]);
						tmp = tmp->lchild;
						s.push(tmp);
					}
					++index;
				}
				tmp = s.top(), s.pop();
				++index;
				if (array[index] != -1) {
					tmp->rchild = new node(array[index]);
					tmp = tmp->rchild;
					s.push(tmp);
					++index;
				}
			}
		}
		
		node<T> *prev, *error1, *error2;
		void recover_binary_search_tree()
		{
			prev = nullptr, error1 = nullptr, error2 = nullptr;
			error(root);
			T tmp = error1->value;
			error1->value = error2->value;
			error2->value = tmp;
		}
		
		void error(node<T>* root)
		{
			if (root == nullptr) return;
			error(root->lchild);
			if (prev) {
				if (root->value < prev->value) {
					if (error1 == nullptr)
						error1 = prev;
					else if (error2 == nullptr);
						error2 = root;
				}
			}
			prev = root;
			error(root->rchild);
		}
};

int main()
{
	BTRee<int> tree;
	vector<int> array{3, 1, -1, -1, 4, 2, -1, -1, -1};
	tree.create(array);
	tree.inorder();
	tree.recover_binary_search_tree();
	tree.inorder();
	return 0;
}