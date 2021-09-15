#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int MAX_N = 52;
int matrix[MAX_N][MAX_N];

int main() {
	ofstream out_file;
	ifstream in_file;
	out_file.open("text/output.txt");
	in_file.open("text/input.txt");
	int tc;
	in_file >> tc;
	for (int c = 1; c <= tc; ++c)
	{
		int n;
		in_file >> n;
		unordered_set<int> coords_set;
		for (int i = 0; i < n; ++i)
		{
			string row; in_file >> row;
			for (int j = 0; j < n; ++j)
			{
				if (row[j] == 'X')matrix[i][j] = 1;
				else if (row[j] == 'O')matrix[i][j] = -1;
				else matrix[i][j] = 0;
			}
		}
		int min_win = n + 2, min_count = 0;
		for (int row = 0; row < n; ++row)
		{
			int cur_win = n, last_zero = -1;
			for (int col = 0; col < n; ++col)
				if (matrix[row][col] == -1)goto h;
				else cur_win -= matrix[row][col], last_zero = (matrix[row][col] == 0 ? row * n + col : last_zero);
			if (cur_win == min_win)++min_count;
			else if (cur_win < min_win) min_win = cur_win, min_count = 1;
			if (cur_win == 1) coords_set.insert(last_zero);
		h:;
		}

		for (int col = 0; col < n; ++col)
		{
			int cur_win = n, last_zero = -1;
			for (int row = 0; row < n; ++row)
				if (matrix[row][col] == -1)goto f;
				else cur_win -= matrix[row][col], last_zero = (matrix[row][col] == 0 ? row * n + col : last_zero);
			if (cur_win == min_win)++min_count;
			else if (cur_win < min_win) min_win = cur_win, min_count = 1;
			if (cur_win == 1) coords_set.insert(last_zero);
		f:;
		}

		out_file << "Case #" << c << ": ";
		if (min_win == 1)
			out_file << min_win << " " << coords_set.size() << endl;
		else if (min_win == n + 2)
			out_file << "Impossible" << endl;
		else
			out_file << min_win << " " << min_count << endl;
	}
	out_file.close();
}