#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int bfs_cost(vector<int>& cnt, unordered_map<char, vector<char>>& graph, char c)
{
	queue<char> q;
	vector<bool> used(27, false);
	vector<int> cost(27, -1);
	q.push(c);
	cost[c - 'A'] = 0, used[c - 'A'] = true;
	while (!q.empty())
	{
		char top = q.front(); q.pop();
		for (char ch : graph[top])
		{
			if (!used[ch - 'A']) {
				used[ch - 'A'] = true;
				q.push(ch);
				cost[ch-'A'] = cost[top-'A'] + 1;
			}
		}
	}
	int total_cost = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (cost[i] == -1 && cnt[i] > 0)return -1;
		total_cost += cost[i] * cnt[i];
	}
	return total_cost;

}
int main() {
	ofstream out_file;
	ifstream in_file;
	out_file.open("text/output.txt");
	in_file.open("text/input.txt");
	int tc;
	in_file >> tc;
	for (int c = 1; c <= tc; ++c)
	{
		string s;
		in_file >> s;
		vector<int> cnt(26, 0);
		for (char i : s)++cnt[i-'A'];

		int K;
		in_file >> K;
		unordered_map<char, vector<char>> graph;
		for (int i = 0; i < K; ++i)
		{
			string pair; in_file >> pair;
			graph[pair[1]].push_back(pair[0]);
		}
		int min_cost = -1;
		bool flag = false;
		for (int c = 'A'; c <= 'Z'; ++c)
		{
			int cost = bfs_cost(cnt, graph, c);
			if (cost != -1 && !flag)min_cost = cost, flag = true;
			else if (cost != -1)min_cost = min(min_cost, cost);
		}
		out_file << "Case #" << c << ": " << min_cost << endl;
	}
	out_file.close();
}