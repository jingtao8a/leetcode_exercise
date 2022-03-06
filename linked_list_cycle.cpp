#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(nullptr) {}
};

ListNode *create_link_cycle(std::vector<int>& num, int point)
{
	ListNode *head = nullptr, *tmp, *new_node, *tail;
	int size = num.size();
	for (int i = 0; i < size; i++) {
		if (head == nullptr) {
			head = new ListNode(num[i]);
			tail = head;
		} else {
			new_node = new ListNode(num[i]);
			tail->next = new_node;
			tail = new_node;
		}
		
		if (i == point - 1) {
			tmp = tail;
		}
	}
	tail->next = tmp;
	return head;
}

ListNode* deleteCycle(ListNode *head)
{
	ListNode *slow = head, *fast = head;
	do {
		if (fast == nullptr || fast->next == nullptr) return nullptr;//no cycle
		fast = fast->next->next;
		slow = slow->next;
	} while (slow != fast);
	//slow == fast
	fast = head;
	while (fast != slow) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

int main()
{
	std::vector<int> num = {3, 2, 0, 4};
	ListNode* head = create_link_cycle(num, 1);
	ListNode* res = deleteCycle(head);
	std::cout << res->val;
	return 0;
}