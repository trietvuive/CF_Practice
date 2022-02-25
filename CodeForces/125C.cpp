#include<bits/stdc++.h>
using namespace std;

int m[150][150];
int main()
{
	int n; cin >> n;
	int left = 1, right = n;
	while (left < right)
	{
		int mid = (left + right + 1) / 2;
		if (mid * (mid - 1) / 2 > n)
			right = mid - 1;
		else left = mid;
	}
	m[1][1] = 1, m[1][2] = 2, m[2][1] = 1, m[2][2] = 3,
		m[3][1] = 2, m[3][2] = 3;
	cout << left << endl;
	for (int i = 3, idx = 3; i + idx <= n; ++idx)
	{
		for (int j = 1; j <= idx; ++j)
			m[j][idx] = m[idx + 1][j] = ++i;
	}
	for (int i = 1; i <= left; ++i, puts(""))
		for (int j = 1; j < left; ++j)
			printf("%d ", m[i][j]);
}