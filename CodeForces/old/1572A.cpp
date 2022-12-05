#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> dp, vis;

bool dfs(int u)
{
	vis[u] = 2;
	for (auto v : graph[u])
	{
		//check for cycle
		if (vis[v] == 2 || (!vis[v] && dfs(v)))return true;
		dp[u] = max(dp[u], dp[v] + (u < v));
	}
	vis[u] = 1;
	return false;
}
int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n, f = 1;
		cin >> n;
		graph.assign(n, {});
		vis.assign(n, 0);
		dp.assign(n, 1);
		for (int i = 0; i < n; ++i)
		{
			int k; cin >> k;
			while (k--)
			{
				int v; cin >> v;
				graph[i].push_back(v-1);
			}
		}
		bool no_cycle = true;
		for (int i = 0; i < n; ++i)
			no_cycle &= !(!vis[i] && dfs(i));
		cout << (no_cycle ? *max_element(dp.begin(), dp.end()) : -1) << endl;
	}
}