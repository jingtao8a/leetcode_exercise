#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct node{
	int val;
	node *next;
	node(int v) : val(v), next(nullptr) {}	
};

node* create_link(vector<int>& num)
{
	node *head = nullptr, *tail = nullptr;
	for (int i = 0; i < num.size(); ++i) {
		if (head == nullptr) {
			head = new node(num[i]);
			tail = head;
		} else {
			tail->next = new node(num[i]);
			tail = tail->next;
		}
	}
	return head;
}

void display(node *head)
{
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

struct cmp{
	bool operator()(node* h1, node* h2)
	{
		return h1->val > h2->val;
	}
};

int main()
{
	vector<int> num1{1, 4, 5}, num2{1, 3, 4}, num3{2, 6};
	node* h1, *h2, *h3, *ans = nullptr, *tail = nullptr;
	h1 = create_link(num1);
 	h2 = create_link(num2);
 	h3 = create_link(num3);
	priority_queue<node*, vector<node*>, cmp> q;
	q.push(h1);
	q.push(h2);
	q.push(h3);
	while (!q.empty()) {
		node* tmp = q.top();
		q.pop();
		if (ans == nullptr) {
			ans = tmp;
			tail = tmp;
			tmp = tmp->next;
			tail->next == nullptr;
		} else {
			tail->next = tmp;
			tmp = tmp->next;
			tail = tail->next;
			tail->next = nullptr;
		}
		if (tmp) {
			q.push(tmp);
		}
	}
	display(ans);
	return 0;
}
