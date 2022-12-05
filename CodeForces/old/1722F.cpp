#include<bits/stdc++.h>
using namespace std;
int tc, row, col;
char ch[55][55];
bool vis[55][55];
void mark(int,int);

bool dfs(int r, int c) {
	mark(r, c), ch[r][c] = '.';
	if(ch[r+1][c] == '*' && ch[r+1][c-1] == '*') {
		mark(r+1, c), mark(r+1, c-1);
		ch[r+1][c] = '.', ch[r+1][c-1] = '.';
		return true;
	}
	else if(ch[r+1][c] == '*' && ch[r+1][c+1] == '*') {
		mark(r+1,c), mark(r+1, c+1);
		ch[r+1][c] = '.', ch[r+1][c+1] = '.';
		return true;
	}
	else if(ch[r][c+1] == '*' && ch[r+1][c+1] == '*') {
		mark(r, c+1), mark(r+1, c+1);
		ch[r][c+1] = '.', ch[r+1][c+1] = '.';
		return true;
	}
	else if(ch[r+1][c] == '*' && ch[r][c+1] == '*') {
		mark(r+1, c), mark(r, c+1);
		ch[r+1][c] = '.', ch[r][c+1] = '.';
		return true;
	}
	return false;
}
void mark(int r, int c) {
	for(int i = r-1; i <= r+1; ++i)
		for(int j = c-1; j <= c+1; ++j)
			vis[i][j] = true;
}
bool solve() {
	memset(ch, 0, sizeof ch);
	memset(vis, 0, sizeof vis);
	cin >> row >> col;
	for(int i = 1; i <= row; ++i)
		for(int j = 1; j <= col; ++j)
			cin >> ch[i][j];

	for(int i = 1; i <= row; ++i)
			for(int j = 1; j <= col; ++j)
				if(ch[i][j] == '*' && vis[i][j]) 
					return false;
				else if(ch[i][j] == '*' && !dfs(i, j))
					return false;

	return true;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> tc;
	while(tc--) {
		if(solve()) cout << "YES\n";
		else cout << "NO\n";
	}
}
