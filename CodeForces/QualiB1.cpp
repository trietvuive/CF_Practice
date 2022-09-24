#include<bits/stdc++.h>
using namespace std;
char mat[102][102];
bool vis[102][102];
int r,c;
void print_mat();

bool possible(int row, int col) {
	cout << row << ' ' << col << endl;
	if(row < 1 || row > r || col < 1 || col > c || vis[row][col]) return true;
	vis[row][col] = true;
	if(mat[row][col] == '#') {
		cout << "a rock\n";
		return true;
	}

	cout << "Visited " << row << ' ' << col << endl;

	int potential_trees = (mat[row+1][col] != '#') + (mat[row-1][col] != '#') + 
				(mat[row][col-1] != '#') + (mat[row][col+1] != '#');
	
	if(potential_trees < 2)
		return mat[row][col] != '^';

	char temp = mat[row][col];
	mat[row][col] = '^';
	if(!possible(row+1, col) || !possible(row-1, col) ||
	   !possible(row, col-1) || !possible(row, col+1)) return false;
	
	int actual_trees = (mat[row+1][col] == '^') + (mat[row-1][col] == '^') + 
				(mat[row][col-1] == '^') + (mat[row][col+1] == '^');
	if(actual_trees < 2) {
		mat[row][col] = temp;
		return temp != '^';
	}
	return true;

}

void print_mat() {
	for(int i = 1; i <= r; ++i, cout << '\n')
		for(int j = 1; j <= c; ++j)
			cout << mat[i][j];
}

void solve(int tc) {
	cin >> r >> c;
	memset(mat, '#', sizeof mat);
	for(int i = 1; i <= r; ++i)
		for(int j = 1; j <= c; ++j)
			cin >> mat[i][j];
	
	for(int i = 1; i <= r; ++i) {
		for(int j = 1; j <= c; ++j) {
			if(!possible(i, j)) {
				cout << "Case #" << tc << ": Impossible\n";
				return;
			}
		}
	}

	cout << "Case #" << tc << ": Possible\n";
	print_mat();
}
int main() {
	freopen("in/sample.txt", "r", stdin);
	freopen("out/sample.txt", "w", stdout);
	ios_base::sync_with_stdio(false);

	int tc; cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		solve(i);
	}
}
