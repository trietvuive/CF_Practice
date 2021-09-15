#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (b < a) swap(a, b);
		int left = 0, right = 1e9 + 7;
		while (left < right)
		{
			int m = (left + right) >> 1;
			int xx = x, yy = y;
			xx -= m * a, yy -= m * a;
			if (b > a && xx / (b - a) + yy / (b - a) < m)
				right = m;
			else if (xx >= 0 && yy >= 0)
				left = m + 1;
			else
				right = m;
		}
		cout << left - 1 << endl;
	}
	return 0;
}
