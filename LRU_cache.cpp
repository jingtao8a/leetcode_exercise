#include <iostream>
#include <unordered_map>
#include <list>
#include <utility>

using namespace std;

class LRUcache{
	private:
		list<pair<int, int>> cache;
		unordered_map<int, list<pair<int, int>>::iterator> hash;
		int size;
	public:
		LRUcache(int n) : size(n) {}
		
		int get(int key)
		{
			auto it = hash.find(key);
			if (it == hash.end()) {
				return -1;
			} else {
				int tmp = it->second->second;
				cache.splice(cache.begin(), cache, it->second);
				return tmp;
			}
		}
		
		void put(int key, int value)
		{
			auto it = hash.find(key);
			if (it == hash.end()) {
				cache.push_front(pair<int, int>(key, value));
				hash[key] = cache.begin();
				if (cache.size() > size) {
					hash.erase(cache.back().first);
					cache.pop_back();
				}
			} else {
				it->second->second = value;
				cache.splice(cache.begin(), cache, it->second);
			}
		}
		
};
LRUcache cache(2);

int main()
{
	cache.put(1, 1);
	cache.put(2, 2);
	cout << cache.get(1) << endl;
	cache.put(3, 3);
	cout << cache.get(2) << endl;
	cache.put(4, 4);
	cout << cache.get(1) << endl;
	cout << cache.get(3) << endl;
	cout << cache.get(4) << endl;
	return 0;
}