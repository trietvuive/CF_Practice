#include<bits/stdc++.h>
using namespace std;
char board[9][9];

int solve_first() {
	unordered_set<int> s;
	for(int i = 0; i < 9; ++i) s.insert(i);

	for(int i = 0, j = 0; i < 9; ++i, ++j) s.erase(board[i][j] - '0');
	for(int i = 1, j = 8; i < 9; ++i, --j) s.erase(board[i][j] - '0');

	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < 3; ++j) 
			s.erase(board[i][j] - '0');
	return *s.begin();
}
int solve() {
	int solved = 0;
	for(int i = 0; i < 9; ++i)
		for(int j = 0; j < 9; ++j)
			cin >> board[i][j];
	
	if(board[0][0] != '.') return board[0][0] - '0';
	else return solve_first();
}
int main() {
	freopen("in/sample.txt", "r", stdin);
	freopen("out/sample.txt", "w", stdout);
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	cerr << tc << endl;
	int ans = 0;
	while(tc--) ans += solve();
	cout << ans << '\n';
}
