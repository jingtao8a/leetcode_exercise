#include <iostream>
#include <vector>
using namespace std;


class UF{
	private:
		vector<int> id, size;
	public:
		UF(int n) : id(n), size(n, 1) 
		{
			for (int i = 0; i < n; ++i) {
				id[i] = i;
			}	
		}
		
		int find(int p) 
		{
			while (p != id[p]) {
				id[p] = id[id[p]];
				p = id[p];
			}
			return p;
		}
		
		void connect(int p, int q) 
		{
			int i = find(p), j = find(q);
			if (i != j) {
				if (size[i] < size[j]) {
					id[i] = j;
					size[j] = size[i] + 1 > size[j] ? size[i] + 1 : size[j]; 
				} else {
					id[j] = i;
					size[i] = size[j] + 1 > size[i] ? size[j] + 1 : size[i];
				}
			}
		}
		
		bool isconnect(int p, int q)
		{
			return find(p) == find(q);
		}
};

vector<vector<int>> findRedundantConnection(vector<vector<int>>& edges)
{
	int n = edges.size();
	UF uf(n + 1);
	vector<vector<int>> ans;
	for (int i = 0; i < n; ++i) { 
		if (uf.isconnect(edges[i][0], edges[i][1])) {
			ans.push_back(edges[i]);
			continue;
		}
		uf.connect(edges[i][0], edges[i][1]);
	}
	return ans;
}

int main()
{
	vector<vector<int>> edges(3);
	edges[0] = vector<int>{1, 2};
	edges[1] = vector<int>{1, 3};
	edges[2] = vector<int>{2, 3};
	
	vector<vector<int>> ans = findRedundantConnection(edges);
	for (int i = 0; i < ans.size(); ++i) {
		cout << "[" << ans[i][0] << ", " << ans[i][1] << "]" << endl;
	}
	return 0;
}