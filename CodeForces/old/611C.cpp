#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 502;
int row[MAX_N][MAX_N], col[MAX_N][MAX_N];
char s[MAX_N][MAX_N];
int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= m; ++j)
		{
			row[i][j] = row[i - 1][j] + row[i][j - 1] - row[i-1][j-1] + (s[i][j] == '.' && s[i][j - 1] == '.');
			col[i][j] = col[i - 1][j] + col[i][j - 1] - col[i-1][j-1] + (s[i][j] == '.' && s[i - 1][j] == '.');
		}
	}
	int num_query; cin >> num_query;
	for (int i = 0; i < num_query; ++i)
	{
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		int res = row[r2][c2] - row[r2][c1] - row[r1 - 1][c2] + row[r1 - 1][c1] + col[r2][c2] - col[r2][c1 - 1] - col[r1][c2] + col[r1][c1 - 1];
		printf("%d\n", res);
	}
}
