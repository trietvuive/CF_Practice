#include <bits/stdc++.h>

using namespace std;

int P;

int K, R, C;
int grid[100][100];

int main() {
	cin >> P;
	while (P--) {
		cin >> K >> R >> C;
		map<pair<int, int>, int> m;	
		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j) {
				char c;
				cin >> c;
				if (c != '-') {
					m[make_pair(i, j)] = c;
					grid[i][j] = c - '0';
				} else {
					grid[i][j] = 0;
				}
				// cout << grid[i][j] << ' ';
			}
			// cout << endl;
		}	

		int N;
		cin >> N;
		// cout << "DEBUG: " << N << endl;

		for (int i = 0; i < N; ++i) {
			int region_size = 0;
			vector<pair<int, int>> region;
			map<int, int> used;

			cin >> region_size;

			for (int j = 0; j < region_size; ++j) {
				char _;
				cin >> _; // (
				int r, c;
				cin >> r; // r
				cin >> _; // ,
				cin >> c; // c
				cin >> _; // )
	
				region.emplace_back(r,c);
				if (grid[r][c] != 0) {
					used[grid[r][c]] = 1;
				}
			}

			int cur = 1;
			for (auto [r,c] : region) {
				while (used[cur]) ++cur;
				if (grid[r][c] == 0) {
					grid[r][c] = cur++;	
				}	
			}
		}

		cout << K << endl;

		for (int i = 1; i <= R; ++i) {
			for (int j = 1; j <= C; ++j) {
				cout << grid[i][j] << ' ';
			} cout << endl;
		}	

	}	
	return 0;
}
