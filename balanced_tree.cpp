#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;

template <class T>
struct node{
	T value;
	node* lchild;
	node* rchild;
	node(const T& v_) : value(v_), lchild(nullptr), rchild(nullptr) {}
};

template <class T>
class BTree{
	private:
		typedef node<T> 	node_type;
		typedef node_type* 	node_ptr;
	
		node_ptr root;
	public:
		BTree() : root(nullptr) {}
		
		void create_tree() 
		{
			__create_tree(root);	
		}
		bool is_balanced()
		{
			bool flag = true;
			if (root == nullptr) return flag;
			__is_balanced(root, flag);
			return flag;
		}
		
		int height()
		{
			return __height(root);
		}
	private:
		void __create_tree(node_ptr& root)
		{
			T tmp;
			cin >> tmp;
			if (tmp == '#' || tmp == 0) {
				return;
			} else {
				root = new node_type(tmp);
				__create_tree(root->lchild);
				__create_tree(root->rchild);
			}
		}
		
		int __height(node_ptr root)
		{
			if (root == nullptr) {
				return 0;
			}
			int left = __height(root->lchild);
			int right = __height(root->rchild);
			return left > right ? left + 1 : right + 1;
		}
		
		void __is_balanced(node_ptr root, bool& flag) 
		{
			if (root != nullptr) {
				if (abs(__height(root->lchild) - __height(root->rchild)) > 1) {
					flag = false;
				}
				__is_balanced(root->lchild, flag);
				__is_balanced(root->rchild, flag);
			}
		}
};
int main()
{
	BTree<char> tree;
	tree.create_tree();
	std::cout << tree.is_balanced();
	return 0;
}