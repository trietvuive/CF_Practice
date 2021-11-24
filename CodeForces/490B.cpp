#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
unordered_map<int, int> parent, graph;

int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
int main()
{
	int n; cin >> n;
	parent[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b; cin >> a >> b;
		if (!b) b = -1;
		graph[a] = b;
		parent[b] = a, graph[a] = b;
		if (parent.find(a) == parent.end())parent[a] = a;
	}
	int odd = -1, leader = -1, even = 0;
	for (const auto& entry : graph)
		if ((leader = find_set(entry.first)) != 0)
		{
			odd = leader;
			break;
		}
	even = graph[even];
	for (int i = 1; i <= n; ++i)
		if (i % 2)cout << odd << " ", odd = graph[odd];
		else cout << even << " ", even = graph[even];

}