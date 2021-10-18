#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
const int MAX = 2e4 + 5;
int a[MAX], b[MAX];
//1269B. Page 49, sort rating DESC
int main()
{
	int n, m, ans = 1e9+7;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 0; i < n; ++i)cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; ++i)
	{
		int dist = ((b[i] - a[0]) % m + m) % m;
		int j = 0;
		for (; j < n; ++j)
			if ((a[j] - b[(j + i) % n] + dist) % m) break;
		if (j == n)ans = min(ans, dist);
	}
	cout << ans << endl;
}