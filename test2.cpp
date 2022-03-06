#include <iostream>
#include <vector>
using namespace std;

struct node{
	int value;
	node *next;
	node(int v) : value(v), next(nullptr) {}	
};

node *create_link(vector<int>& num)
{
	if (num.size() == 0) return nullptr;
	node *head = new node(num[0]);
	node *tail = head;
	for (int i = 1; i < num.size(); ++i) {
		tail->next = new node(num[i]);
		tail = tail->next;
	}
	return head;
}

node* change(node *head)
{
	node *pre, *p;
	pre = head;
	p = head->next;
	while (p) {
		if (p->value % 2 == 1) {
			pre->next = p->next;
			p->next = head;
			head = p;
			p = pre->next;
		} else {
			pre = p;
			p = pre->next;
		}
	}
	return head;
}

int main()
{
	vector<int> num{1, 2, 3, 5, 4, 6, 7};
	node *head = create_link(num);
	head = change(head);
	while (head) {
		cout << head->value <<" ";
		head = head->next;
	}
 	return 0;
}
