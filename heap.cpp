#include <iostream>
#include <vector>
using namespace std;

class myheap{
	vector<int> q;
	public:
		myheap() : q(1) {}
		void push(int val)
		{
			q.push_back(val);
			shift_up(q.size() - 1);
		}
		int pop()
		{
			if (q.size() == 1) return 0;
			int tmp = q[1];
			swap(q[1], q[q.size() - 1]);
			q.pop_back();
			shift_down(1);
			return tmp;
		}
		
		void swap(int& a, int& b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		
		void shift_up(int k)
		{
			while (true) {
				if (k == 1) return;
				if (q[k / 2] < q[k]) {
					swap(q[k / 2], q[k]);
					k = k / 2;
				} else {
					return;
				}
			}
		}
		
		void shift_down(int k)
		{
			while (true) {
				if (2 * k >= q.size()) return;
				k = 2 * k;
				if (k + 1 < q.size() && q[k + 1] > q[k]) {
					k++;
				}
				if (q[k / 2] < q[k]) {
					swap(q[k / 2], q[k]);
				}
			}
		}
};

int main()
{
	myheap h;
	h.push(4);
	h.push(3);
	h.push(9);
	h.push(100);
	int tmp;
	while (tmp = h.pop()) {
		cout << tmp << " ";
	}
	cout << endl;
 	return 0;
}
