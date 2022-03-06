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
class BTree{
	node<T>* head;
	public:
		BTree() : head(nullptr) {}
		
		void tree_construct(vector<int>& preorder, vector<int>& inorder)
		{
			head = __tree_construct(preorder, 0, inorder, 0, inorder.size());
		}
		
		void preorder_NR()
		{
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
	private:
		node<T>* __tree_construct(vector<int>& preorder, int p_s, vector<int>& inorder, int i_s, int size)
		{
			if (size == 0) 
				return nullptr;
			node<T>* head = new node(preorder[p_s]);
			int i;
			for (i = 0; i < size; i++) {
				if (inorder[i + i_s] == preorder[p_s]) {
					break;
				}
			}
			head->lchild = __tree_construct(preorder, p_s + 1, inorder, i_s, i);
			head->rchild = __tree_construct(preorder, p_s + i + 1 ,inorder, i_s + i + 1, size - i - 1);
			return head;
		}
};

int main()
{
	BTree<int> tree;
	vector<int> preorder{4, 9, 20, 15, 7}, inorder{9, 4, 15, 20, 7};
	tree.tree_construct(preorder, inorder);
	tree.preorder_NR();
	return 0;
}
