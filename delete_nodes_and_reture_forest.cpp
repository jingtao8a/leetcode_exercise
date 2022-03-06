#include <iostream>
#include <vector>
#include <unordered_set>
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

		vector<node<T>*> delNodes(vector<T>& to_delete)
		{
			vector<node<T>*> forest;
			unordered_set<T> dict;
			for (int i = 0; i < to_delete.size(); ++i) {
				dict.insert(to_delete[i]);
			}
			helper(head, dict, forest);
			if (head) forest.push_back(head);
			return forest;
		}
	private:
		void helper(node<T>* &head, unordered_set<T>& dict, vector<node<T>*>& forest)
		{
			if (head == nullptr) return;
			helper(head->lchild, dict, forest);
			helper(head->rchild, dict, forest);
			if (dict.count(head->value)) {
				if (head->lchild) forest.push_back(head->lchild);
				if (head->rchild) forest.push_back(head->rchild);
				delete head;
				head = nullptr;
			}
		}
		void __create(node<T>*& head, vector<T>& array, int& index);

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

void preorder_NR(node<int>* head)
{
	node<int>* tmp = head;
	stack<node<int>*> s;
	while (!s.empty() || tmp) {
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

int main()
{
	BTRee<int> tree;
	vector<int> array{1, 2, 4, 0, 0, 5, 0, 0, 3, 6, 0, 0, 7, 0, 0};
	tree.create(array);	
	vector<int> to_delete{3, 5};
	vector<node<int>*> ans = tree.delNodes(to_delete);
	for (int i = 0; i < ans.size(); ++i) {
		preorder_NR(ans[i]);
	}
	return 0;
}
