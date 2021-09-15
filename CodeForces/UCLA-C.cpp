#include<bits/stdc++.h>
using namespace std;
vector<int> g[902];
vector<bool> used(902);
void dfs(int v)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i)
	{
		int to = g[v][i];
		if (!used[to])dfs(to);
	}
}
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int from, to;
		cin >> from >> to;
		g[from].push_back(to);
		g[to].push_back(from);
	}
	int component = 0;
	for (int i = 1; i <= N; ++i)
	{
		used[i] = false;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (!used[i])
		{
			dfs(i);
			++component;
		}
		if (component > 1) break;
	}
	if (component > 1)cout << "NO" << endl;
	else cout << "YES" << endl;
}