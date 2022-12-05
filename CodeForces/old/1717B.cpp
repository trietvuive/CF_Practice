#include<bits/stdc++.h>
using namespace std;
void solve() {
	int n,k,row,col; cin >> n >> k >> row >> col;
	
	row = (row - 1) % k, col = (col - 1) % k;
	int k_temp = k;
	vector<vector<char>> board(k, vector<char> (k, '.'));
	board[row][col] = 'X';
	int r = 0, c = 0;
	while(--k_temp) {
		if(r == row) ++r;
		if(c == col) ++c;
		board[r++][c++] = 'X';
	}

	for(int i = 0; i < n/k; ++i)
		for(int r = 0; r < k; ++r, cout << '\n')
			for(int j = 0; j < n/k; ++j)
				for(int c = 0; c < k; ++c)
					cout << board[r][c];

}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) solve();
}
