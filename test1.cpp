#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <list>

using namespace std;

unordered_map<int, int> m;
unordered_set<int> s;
list<int> l1, l2;

void display(list<int>& l)
{
	list<int>::iterator it = l.begin();
	while (it != l.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{
	/*
	m[0] = 1;
	m[2] = 3;
	m[3] = 3;
	unordered_map<int, int>::iterator it = m.begin();
	while (it != m.end()) {
		cout << (*it).second << "\t";
		++it;
	}
	*/
	l2.push_back(0);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(4);
	l1.splice(l1.begin(), l2, l2.begin());
	display(l1);
	display(l2);
	return 0;
}