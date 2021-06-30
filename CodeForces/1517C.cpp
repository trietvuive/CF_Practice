/*#include<bits/stdc++.h>
int n, p[501], matrix[501][501];
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> p[i];
		int x = i, y = i;
		for (int j = 1; j <= p[i]; ++j)
		{
			matrix[x][y] = p[i];
			if (y > 1 && !matrix[x][y - 1])--y;
			else ++x;
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
			cout << matrix[i][j] << " ";
		cout << endl;
	}

}
*/