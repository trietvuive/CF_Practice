#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
const int MAX = 2e5 + 2;
int y[MAX], n, m, e, m_sz;
ll cost;

int main() {
	queue<int> q;
	unordered_set<int> visited;
	
	cin >> n >> m;
	m_sz = m;
	for (int i = 0; i < n; ++i)
		cin >> e, visited.insert(e), q.push(e);
	int level = 0;
	while (m) {
		int sz = q.size();
		for (int i = 0; i < sz; ++i) {
			int front = q.front(); q.pop();
			if (!visited.count(front)) y[m--] = front, visited.insert(front), cost += level;
			if (!m) break;

			if (!visited.count(front - 1)) q.push(front - 1);
			if (!visited.count(front + 1)) q.push(front + 1);
		}
		++level;
	}
	cout << cost << endl;
	for (int i = 1; i <= m_sz; ++i) cout << y[i] << ' ';
}