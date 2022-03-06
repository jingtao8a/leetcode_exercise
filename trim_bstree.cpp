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
		
		void trim(int l, int r)
		{
			root = __trim(root, l, r);
		}
		node<T>* p;
		node<T>* __trim(node<T>* root, int l, int r)
		{
			if (root == nullptr) return nullptr;
			if (root->value > r) {
				p = root->lchild;
				p = __trim(p, l, r);
				root->lchild = nullptr;
				__destroy(root);
				root = p;
			} else if (root->value < l) {
				p = root->rchild;
				p = __trim(p, l, r);
				root->rchild = nullptr;
				__destroy(root);
				root = p;
			} else {
				root->rchild = __trim(root->rchild, l, r);
				root->lchild = __trim(root->lchild, l, r);
			}
			return root;
		}
		
		void __destroy(node<T>* root) {
			if (root == nullptr) return;
			__destroy(root->lchild);
			__destroy(root->rchild);
			delete root;
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
};

int main()
{
	vector<int> array{3, 0, -1, 2, 1, -1, -1, -1, 4, -1, -1};
	BTRee<int> tree;
	tree.create(array);
	tree.inorder();
	tree.trim(1, 3);
	tree.inorder();
	return 0;
}