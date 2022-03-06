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

int count(node *head)
{
	int sum = 0;
	while (head) {
		sum++;
		head = head->next;
	}
	return sum;
}

node *k_flip(node *head, int k)
{
	node *ans_head = nullptr, *ans_tail = nullptr;
	node *new_head = nullptr, *new_tail = nullptr;
	int sum = count(head);
	if (sum < k) return head;
	
	int cycle = sum / k;
	node *p = head, *pnext = p->next;
	while (cycle--) {
		for (int i = 1; i <= k; i++) {
			if (new_head == nullptr) {
				p->next = new_head;
				new_head = p;
				new_tail = new_head;
			} else {
				p->next = new_head;
				new_head = p;
			}
			p = pnext;
			if (pnext) pnext = pnext->next;
		}
		if (ans_head == nullptr) {
			ans_head = new_head;
			ans_tail = new_tail;
		} else {
			ans_tail->next = new_head;
			ans_tail = new_tail;
		}
		new_head = nullptr;
	}
	if (p) {
		ans_tail->next = p;
	}
	return ans_head;
}

void disp(node* head)
{
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	vector<int> num{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	node *head = create_link(num);
	disp(head);
	head = k_flip(head, 3);
	disp(head);
 	return 0;
}
