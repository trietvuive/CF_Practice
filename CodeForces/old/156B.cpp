#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
int a[MAX_N], c[MAX_N], d;

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		if (a[i] > 0) ++c[a[i]];
		else --c[-a[i]], ++d;
	}
	int t = count(c + 1, c + n + 1, m - d);
	for (int i = 1; i <= n; ++i)
	{
		if (c[abs(a[i])] != m - d)
			puts(a[i] > 0 ? "Lie" : "Truth");
		else if (t == 1)
			puts(a[i] > 0 ? "Truth" : "Lie");
		else
			puts("Not defined");
	}
}