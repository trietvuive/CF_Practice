#include<bits/stdc++.h>
using namespace std;
int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		bool has_black = false, cross_black = false, is_cell = false;
		int n, m, r, c; cin >> n >> m >> r >> c;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				char cell; cin >> cell;
				if (cell == 'B')
					has_black = true, cross_black |= (i == r) || (j == c),
					is_cell |= (i == r) && (j == c);
			}
		}
		cout << (has_black ? cross_black ? is_cell ? 0 : 1 : 2 : -1) << endl;
	}


}