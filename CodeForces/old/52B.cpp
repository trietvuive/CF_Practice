#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e4 + 2;
int row[MAX_N], col[MAX_N];

int main()
{
	int m, n; cin >> m >> n;
	vector<int> coords;
	for (int i = 0; i < m; ++i)
	{
		string s; cin >> s;
		for (int j = 0; j < n; ++j)
		{
			row[i] += (s[j] == '*');
			col[j] += (s[j] == '*');
			if (s[j] == '*')
				coords.push_back(i * n + j);
		}
	}
	ll ans = 0;
	for (int i = 0; i < coords.size(); ++i)
	{
		int r = coords[i] / n, c = coords[i] % n;
		ans += (row[r] - 1) * (col[c] - 1);
	}
	cout << ans << endl;
}