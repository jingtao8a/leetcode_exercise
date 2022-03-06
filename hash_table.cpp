#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <class T>
class HashTable{
	private:
		vector<list<T>> hash_table;
		int myhash(const T& obj)
		{
			return hash(obj, hash_table.size());
		}
		
	public:
		HashTable() : hash_table(10) {}
		bool contains(const T& obj)
		{
			int hash_value = myhash(obj);
			list<T>& slot = hash_table[hash_value];
			typename list<T>::const_iterator it = slot.cbegin();
			for (; it != slot.cend(); ++it) {
				if (*it == obj) {
					return true;
				}
			}
			return false;
		}
		
		bool insert(const T& obj)
		{
			if (contains(obj))
				return false;
			int hash_value = myhash(obj);
			list<T>& slot = hash_table[hash_value];
			slot.push_front(obj);
			return true;
		}
		
		bool remove(const T& obj)
		{
			list<T>& slot = hash_table[myhash(obj)];
			auto it = find(slot.begin(), slot.end(), obj);
			if (it == slot.end())
				return false;
			slot.erase(it);
			return true;
		}
		
		int hash(const T& key, const int& tableSize) 
		{
			return key % tableSize;
		}
};
int main()
{
	HashTable<int> hash;
	hash.insert(1);
	hash.insert(2);
	cout << hash.contains(1) << " " << hash.contains(2);
 	return 0;
}
