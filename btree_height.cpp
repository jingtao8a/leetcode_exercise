#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <cstdio>

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
		
		void preorder_NR()
		{
			stack<node_ptr> s;
			node_ptr tmp = root;
			while (!s.empty() || tmp) {// stack is not empty or tmp is not null
				while (tmp) {
					cout << tmp->value << "\t";
					s.push(tmp);
					tmp = tmp->lchild;
				}
				if (!s.empty()) {
					tmp = s.top(), s.pop();
					tmp = tmp->rchild;
				}
			}
			cout << endl;
		}
		
		void preorder_NR1()
		{
			stack<node_ptr> s;
			node_ptr tmp;
			if (root == nullptr) return;
			s.push(root);
			while (!s.empty()) {
				tmp = s.top(), s.pop();
				cout << tmp->value << "\t";
	
				if (tmp->rchild != nullptr) s.push(tmp->rchild);
				if (tmp->lchild != nullptr) s.push(tmp->lchild);
			}
			cout << endl;
 		}
 		
		void inorder_NR()
		{
			stack<node_ptr> s;
			node_ptr tmp = root;
			while (!s.empty() || tmp) {
				while (tmp) {
					s.push(tmp);
					tmp = tmp->lchild;
				}
				if (!s.empty()) {
					tmp = s.top(), s.pop();
					cout << tmp->value << "\t";
					tmp = tmp->rchild;
				} 
			}
			cout << endl;
		}
		
		void postorder_NR()
		{
			stack<node_ptr> s;
			node_ptr current, last_visit = nullptr;
			current = root;
			while (current) {
				s.push(current);
				current = current->lchild;
			}
			
			while (!s.empty()) {
				current = s.top(), s.pop();
				if (current->rchild == nullptr || current->rchild == last_visit) {
					cout << current->value << "\t";
					last_visit = current;
				} else {
					s.push(current);
					current = current->rchild;
					while (current) {
						s.push(current);
						current = current->lchild;
					}
				}
			}
			cout << endl;
		}
		int height()
		{
			return __height(root);
		}
		
		int height_stack()
		{
			int max_depth = 0;
			__height_stack(max_depth);
			return max_depth;
		}
		
		int height_queue()
		{
			if (root == nullptr) return 0;
			queue<node_ptr> que;
			
			int depth = 0, width = 0;
			node_ptr tmp;
			que.push(root);
			while (!que.empty()) {
				++depth;
				width = que.size();
				while (width--) {
					tmp = que.front(), que.pop();
					if (tmp->lchild != nullptr)	que.push(tmp->lchild);
					if (tmp->rchild != nullptr) que.push(tmp->rchild);
				}
			}
			return depth;
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
		
		void __height_stack(int& max_depth)
		{
			stack<node_ptr> s;
			node_ptr current, last_visit = nullptr;
			current = root;
			while (current) {
				s.push(current);
				current = current->lchild;
			}
			if (s.size() > max_depth)	max_depth = s.size();
			
			while (!s.empty()) {
				current = s.top(), s.pop();
				if (current->rchild == nullptr || current->rchild == last_visit) {
					last_visit = current;
				} else {
					s.push(current);
					current = current->rchild;
					while (current) {
						s.push(current);
						current = current->lchild;
					}
					if (s.size() > max_depth)	max_depth = s.size();
				}
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
};


int main()
{
	BTree<char> btree;
	btree.create_tree();
	btree.preorder_NR1();
	btree.preorder_NR();
	btree.inorder_NR();
	btree.postorder_NR();
	cout << btree.height_stack() << " " << btree.height() << " " << btree.height_queue() << endl;
	return 0;
}
