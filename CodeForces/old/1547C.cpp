#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 102;
int a[MAX_N], b[MAX_N], ans[MAX_N];
int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int k, m, n;
		cin >> k >> m >> n;
		for (int i = 0; i < m; ++i)cin >> a[i];
		for (int i = 0; i < n; ++i)cin >> b[i];

		int a_ptr = 0, b_ptr = 0;
		for (int i = 0; i < m + n; ++i)
		{
			if (a_ptr < m && a[a_ptr] <= k)ans[i] = a[a_ptr], k += a[a_ptr++] == 0;
			else if (b_ptr < n && b[b_ptr] <= k)ans[i] = b[b_ptr], k += b[b_ptr++] == 0;
			else goto endcase;
		}
		for (int i = 0; i < m + n; ++i)cout << ans[i] << (i == m+n-1 ? "\n": " ");
		continue;
		endcase:;
		cout << -1 << endl;
	}
}