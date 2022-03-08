#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int max(int x, int y) {
    return x > y ? x : y;
}
	
vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> hash;
	int max_frequency = 0;
    for (int i = 0; i < nums.size(); ++i) {    
		if (hash.find(nums[i]) == hash.end()) {
        	hash[nums[i]] = 1;
		} else {
			hash[nums[i]]++;
		}
    }
    auto iter = hash.begin();
    while (iter != hash.end()) {
        max_frequency = max(max_frequency, iter->second);
        ++iter;
    }
    vector<int> bucket;
	bucket.resize(max_frequency + 1);
	iter = hash.begin();
	while (iter != hash.end()) {
        bucket[iter->second] = iter->first;
        ++iter;
    }
    return bucket;
}
    
int main()
{
	vector<int> nums{1,1,1,2,2,3};
	int k = 2;
	vector<int> ans = topKFrequent(nums, k);
	cout << "\n";
	for (int i : ans) {
		cout <<  i << " ";
	}
 	return 0;
}
