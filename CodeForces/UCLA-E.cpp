/*#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Edge {
	int w = INF, to = -1;
};
int main()
{
	int n;
	cin >> n;
	vector<pair<int, int>> students;
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		students.push_back({ x,y });
	}
	vector<Edge> min_e(n);
	vector<bool>selected(n, false);
	int total_weight = 0;
	min_e[0].w = 0;
	for (int i = 0; i < n; ++i)
	{
		int v = -1;
		for (int j = 0; j < n; ++j)
		{
			if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
				v = j;
		}
		selected[v] = true;
		total_weight += min_e[v].w;
		for (int to = 0; to < n; ++to)
		{
			int distance = abs(students[to].first - students[v].first) + abs(students[to].second - students[v].second);
			if (distance < min_e[to].w)
				min_e[to] = { distance,v };
		}
	}
	cout << total_weight*2 << endl;

}
*/