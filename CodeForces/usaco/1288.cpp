#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

char board[25][25], stamp[25][25];
bool vis[25][25];
int n,m;

// rotate stamp matrix 90 degree
void rotate() {
	char tmp[25][25];
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			tmp[i][j] = stamp[i][j];

	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			stamp[i][j] = tmp[m-j-1][i];
}

bool check(int r, int c) {
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			if(board[r+i][c+j] == '.' && stamp[i][j] == '*')
				return false;

	return true;
}

void visit(int r, int c) {
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < m; ++j)
			if(stamp[i][j] == '*') 
				vis[r+i][c+j] = true;

}

void rotate_stamp(int r, int c) {
	if(check(r,c)) visit(r,c);

	rotate();
	if(check(r,c)) visit(r,c);

	rotate();
	if(check(r,c)) visit(r,c);

	rotate();
	if(check(r,c)) visit(r,c);
}

bool visit_all() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(board[i][j] == '*' && !vis[i][j])
				return false;

	return true;
}

void solve() {
	cin >> n;
	memset(vis, 0, sizeof vis);

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> board[i][j];

	cin >> m;
	for(int i = 0; i < m; ++i) 
		for(int j = 0; j < m; ++j)
			cin >> stamp[i][j];

	for(int i = 0; i <= n-m; ++i)
		for(int j = 0; j <= n-m; ++j)
			rotate_stamp(i, j);

	if(visit_all()) cout << "YES\n";
	else cout << "NO\n";
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

