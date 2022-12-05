#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 103;
char matrix[MAX_N][MAX_N];
int one_idx[4][2];
int zero_idx[4][2];
void make_zero(int x, int y)
{
	int n = matrix[x][y] + matrix[x + 1][y] + matrix[x][y + 1] + matrix[x + 1][y + 1] - '0' * 4;
	int o_idx = 0, z_idx = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
		{
			if (matrix[x + i][y + j] == '1')
				one_idx[o_idx][0] = x + i, one_idx[o_idx++][1] = y + j;
			else
				zero_idx[z_idx][0] = x + i, zero_idx[z_idx++][1] = y + j;
			matrix[x + i][y + j] = '0';
		}
	if (n == 4)
	{
		printf("%d %d %d %d %d %d\n", x, y, x + 1, y, x+1, y + 1);
		printf("%d %d %d %d %d %d\n", x, y, x, y+1, x+1, y + 1);
		printf("%d %d %d %d %d %d\n", x+1, y, x, y + 1, x + 1, y + 1);
		printf("%d %d %d %d %d %d\n", x, y, x, y + 1, x + 1, y);
	}
	else if (n == 3)
	{
		printf("%d %d %d %d %d %d\n", one_idx[0][0], one_idx[0][1], one_idx[1][0], one_idx[1][1], one_idx[2][0], one_idx[2][1]);
	}
	else if (n == 2)
	{
		printf("%d %d %d %d %d %d\n",zero_idx[0][0], zero_idx[0][1], zero_idx[1][0], zero_idx[1][1], one_idx[0][0], one_idx[0][1]);
		printf("%d %d %d %d %d %d\n", zero_idx[0][0], zero_idx[0][1], zero_idx[1][0], zero_idx[1][1], one_idx[1][0], one_idx[1][1]);
	}
	else if (n == 1)
	{
		printf("%d %d %d %d %d %d\n", one_idx[0][0], one_idx[0][1], zero_idx[0][0], zero_idx[0][1], zero_idx[1][0], zero_idx[1][1]);
		printf("%d %d %d %d %d %d\n", one_idx[0][0], one_idx[0][1], zero_idx[1][0], zero_idx[1][1], zero_idx[2][0], zero_idx[2][1]);
		printf("%d %d %d %d %d %d\n", one_idx[0][0], one_idx[0][1], zero_idx[2][0], zero_idx[2][1], zero_idx[0][0], zero_idx[0][1]);
	}
}
int main()
{
	int tc; 
	cin >> tc;
	int cases = 1;
	while (tc-- > 0)
	{
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> matrix[i][j];
			}
		}
		int k = 0;
		for (int i = 1; i <= n; i += (i == n-2) ? 1 : 2)
		{
			for (int j = 1; j <= m; j += (j == m - 2) ? 1 : 2)
			{
				bool no_row_overlap = n % 2 == 0 || i != n - 1, no_col_overlap = m % 2 == 0 || j != m - 1;
				int cnt = matrix[i + 1][j + 1] == '1';
				if (no_row_overlap)
					cnt += matrix[i][j + 1] == '1';
				if (no_col_overlap)
					cnt += matrix[i + 1][j] == '1';
				if(no_row_overlap && no_col_overlap)
					cnt += matrix[i][j] == '1';
				k += cnt == 4 ? 4 : cnt == 3 ? 1 : cnt == 2 ? 2 : cnt == 1 ? 3 : 0;
			}
		}
		printf("Case #%d\n", cases++);
		cout << k << endl;
		for (int i = 1; i <= n; i += (i == n - 2) ? 1 : 2)
		{
			for (int j = 1; j <= m; j += (j == m - 2) ? 1 : 2)
			{
				make_zero(i, j);
			}
		}
	}

}