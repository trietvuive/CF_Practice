#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 5;
int max_level;
int level_total[MAX];
unordered_map<int, vector<int>> graph;

int binary_search(int volume_total) {
	int left = 0, right = max_level;
	while(left < right) {
		int mid = (left + right) / 2;
		if(level_total[mid] < volume_total) left = mid + 1;
		else right = mid;
	}
	return level_total[left] == volume_total ? volume_total : 
			level_total[left-1];
}

void bfs() {
	queue<int> q;
	unordered_set<int> vis;
	int cur_level = 1;
	max_level = 0;
	q.push(1);

	while(q.size()) {
		int n = q.size();
		for(int i = 0; i < n; ++i) {
			int top = q.front(); q.pop();
			vis.insert(top);
			++level_total[cur_level];

			for(int v : graph[top]) 
				if(vis.find(v) == vis.end())
					q.push(v);
		}
		level_total[cur_level] += level_total[cur_level - 1];
		max_level = max(max_level, cur_level);
		++cur_level;
	}
}

void solve(int tc) {
	memset(level_total, 0, MAX);
	graph.clear();

	int n,q; cin >> n >> q;
	for(int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v), graph[v].push_back(u);
	}

	bfs();

	int volume_total = 0;
	for(int i = 0; i < q; ++i) {
		int query; cin >> query;
		++volume_total; 
	}
	cout << "Case #" << tc << ": " << binary_search(volume_total) << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	for(int i = 1; i <= tc; ++i)
		solve(i);
}
