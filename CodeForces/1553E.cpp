#include<bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 2;
int n, m, in[MAX], s_left[MAX], vis[MAX], cnt[MAX];
bool chk(int s) {
	for (int i = 1; i <= n; ++i) s_left[i] = in[i + s > n ? i + s - n : i + s], vis[i] = 0;
	int M = m;
	for(int i = 1;i<=n;++i)
		if (!vis[i])
		{
			int next = i, c = 0;
			while (!vis[next]) vis[next] = 1, ++c, next = s_left[next];
			M -= c - 1;
			if (M < 0)return false;
		}
	return M >= 0;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			cin >> in[i], ++cnt[i >= in[i] ? i - in[i] : i - in[i] + n];
		for (int i = 0; i < n; ++i)
			if (cnt[i] >= n / 3 && chk(i)) ++ans; else cnt[i] = 0;
		cout << ans << " ";
		for (int i = 0; i < n; ++i)
			if (cnt[i])cout << i << " ", cnt[i] = 0;
		cout << endl;
	}
}