#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 52, MAX_VAL = 1000;
int matrix[MAX_N][MAX_N];

int main() {
	ofstream out_file;
	ifstream in_file;
	out_file.open("text/output.txt");
	in_file.open("text/input.txt");
	int tc;
	in_file >> tc;
	for (int i = 0; i < 52; ++i)for (int j = 0; j < 52; ++j)
		matrix[i][j] = i == 0 ? 1 : MAX_VAL;
	for (int case_n = 1; case_n <= tc; ++case_n)
	{
		out_file << "Case #" << case_n << ": ";
		int n, m, A, B; in_file >> n >> m >> A >> B;
		if (min(A, B) < n + m - 1)
			out_file << "Impossible\n";
		else
		{
			out_file << "Possible \n";
			matrix[0][0] = A - (n + m - 2);
			matrix[n - 1][0] = B - (n + m - 2);
			for (int row = 0; row < n; ++row)
				matrix[row][m - 1] = 1;
			for (int col = 1; col < m; ++col)
				matrix[n - 1][col] = 1;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
				{
					out_file << matrix[i][j] << (j == m - 1 ? "\n" : " ");
					if (i == n-1 || j == m-1 && i != 0)matrix[i][j] = MAX_VAL;
				}
		}
;	}
	out_file.close();
}
