#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;
int ans[N], cmd[N], vis[N];
vector<int> g[N];

int dfs(int i) {
	if(cmd[i] == 0) return ans[i] = g[i][0];
	if(cmd[i] == 1) return ans[i] = !dfs(g[i][0]);
	if(cmd[i] == 2) return ans[i] = dfs(g[i][0]) & dfs(g[i][1]);
	if(cmd[i] == 3) return ans[i] = dfs(g[i][0]) | dfs(g[i][1]);
	if(cmd[i] == 4) return ans[i] = dfs(g[i][0]) ^ dfs(g[i][1]);
	return -1;
}

void dfs1(int v) {
	if(cmd[v] == 0) vis[v] = 1;
	if(cmd[v] == 1) dfs1(g[v][0]);
	if(cmd[v] == 2) {
		if(ans[g[v][0]] && ans[g[v][1]]) 
			dfs1(g[v][0]), dfs1(g[v][1]);
		else if(ans[g[v][0]])
			dfs1(g[v][1]);
		else if(ans[g[v][1]])
			dfs1(g[v][0]);
	}
	if(cmd[v] == 3) {
		if(ans[g[v][0]] && ans[g[v][1]]) return;
		if(!ans[g[v][1]]) dfs1(g[v][0]);
		if(!ans[g[v][0]]) dfs1(g[v][1]);
	}
	if(cmd[v] == 4) {
		dfs1(g[v][0]), dfs1(g[v][1]);
	}
}

void solve() {
	int n; 
	cin >> n;
	vector<int> flippable;
	for(int i = 1; i <= n; ++i) {
		string command; cin >> command;
		int a,b; 
		if(command == "NOT" || command == "IN") {
			cin >> a;
			g[i].push_back(a);
			cmd[i] = (command == "IN" ? 0 : 1);
			if(command == "IN") flippable.push_back(i);
		}	
		else {
			cin >> a >> b;
			g[i].push_back(a);
			g[i].push_back(b);
			cmd[i] = (command == "AND" ? 2 : command == "OR" ? 3 : 4);
		}
	}
	dfs(1);
	dfs1(1);

	for(int i : flippable)
		cout << (ans[1] ^ vis[i]);
	cout << '\n';
}
int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
