#include <iostream>
#include <vector>
#include <stack>
#include <deque>

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
			stack<node<T>*> s;
			node<T>* tmp = head;
			s.push(tmp);
			while (!s.empty()) {
				tmp = s.top(), s.pop();
				cout << tmp->value << " ";
				if (tmp->rchild) s.push(tmp->rchild);
				if (tmp->lchild) s.push(tmp->lchild);
			}	
			cout << endl;
		}
		
		vector<float> average_of_levels()
		{
			deque<node<T>*> q;
			vector<float> ans;
			q.push_back(head);
			node<T>* tmp;
			int width = 1;
			ans.push_back((float)head->value);
			while (!q.empty()) {
				if (width == 0) {
					width = q.size();
					int sum = 0;
					for (int i = 0; i < width; ++i) {
						sum += q[i]->value;
					}
					ans.push_back(sum / (float)width);
				}
				tmp = q.front(), q.pop_front();
				--width;
				if (tmp->lchild) q.push_back(tmp->lchild);
				if (tmp->rchild) q.push_back(tmp->rchild);
			}
			return ans;
		}
		
		void create_NR(vector<T>& array)
		{
			stack<node<T>*> s;
			int index = 0;
			node<T>* tmp;
			while (!s.empty() || array[index] != 0) {
				while (array[index] != 0) {
					if (head == nullptr) {
						head = new node(array[index]);
						tmp = head;
						s.push(tmp);
						++index;
					} else {
						tmp->lchild = new node(array[index]);
						tmp = tmp->lchild;
						s.push(tmp);
						++index;
					}
				}
				tmp = s.top(), s.pop();
				++index;
				if (array[index] != 0) {
					tmp->rchild = new node(array[index]);
					tmp = tmp->rchild;
					s.push(tmp);
					++index;
				}
			}
		}
	private:
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

int main()
{
	vector<int> array{3, 9, 0, 0, 20, 15, 0, 0, 7, 0, 0};
	BTRee<int> tree;
	tree.create(array);
	tree.preorder();
	vector<float> ans = tree.average_of_levels();
	cout << "[";
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i];
		if (i != ans.size() - 1) 
			cout << ", ";
	}
	cout << "]";
	return 0;
}