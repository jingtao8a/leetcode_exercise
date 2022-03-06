#include <iostream>

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
		int max_diameter()
		{
			int diameter = 0;
			__max_diameter(root, diameter);
			return diameter;
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
		
		void __max_diameter(node_ptr root, int& diameter) 
		{
			if (root != nullptr) {
				if (__height(root->lchild) + __height(root->rchild) > diameter) {
					diameter = __height(root->lchild) + __height(root->rchild);
				}
				__max_diameter(root->lchild, diameter);
				__max_diameter(root->rchild, diameter);
			}
		}
};
int main()
{
	BTree<char> tree;
	tree.create_tree();
	std::cout << tree.max_diameter();
	return 0;
}