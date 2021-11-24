#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 2;
int ar[MAX_N][MAX_N], a[MAX_N][MAX_N], b[MAX_N][MAX_N], tpa[MAX_N], tpb[MAX_N];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> ar[i][j], a[i][j] = b[j][i] = ar[i][j];
	for (int i = 0; i < n; ++i)
		sort(a[i], a[i] + m), tpa[i] = unique(a[i], a[i] + m) - a[i];
	for (int i = 0; i < m; ++i)
		sort(b[i], b[i] + n), tpb[i] = unique(b[i], b[i] + n) - b[i];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int aa = lower_bound(a[i], a[i] + tpa[i], ar[i][j]) - a[i],
				bb = lower_bound(b[j], b[j] + tpb[j], ar[i][j]) - b[j];
			cout << max(aa, bb) + max(tpa[i] - aa, tpb[j] - bb) << " ";
		}
		cout << endl;
	}
}