#include <iostream>
#include <utility>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class solution{
	vector<int> origin;
	public:
		solution(vector<int> num) : origin(std::move(num)) {}
		vector<int> reset()
		{
			return origin;
		}
		vector<int> shuffle()
		{
			vector<int> shuffled(origin);
			int n = origin.size();
			srand(time(NULL));
			for (int i = n - 1; i >= 0; --i) {
				swap(shuffled[i], shuffled[rand() % (i + 1)]);
			}
			return shuffled;
		}
};

void display(vector<int> tmp)
{
	for (int i = 0; i < tmp.size(); ++i) {
		cout << tmp[i] << " ";
	}
	cout << endl;
}

int main()
{
	solution obj(vector<int>{1, 2, 3});
	display(obj.shuffle());
	display(obj.shuffle());
	display(obj.reset());
 	return 0;
}
