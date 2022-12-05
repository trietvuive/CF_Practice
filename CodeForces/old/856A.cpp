#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 1;
int vis[MAX + 2], a[102];
int main()
{
	int tc; scanf("%d", &tc);
	while (tc)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		puts("YES");
		int cnt = 0;
		for (int i = 1; i < MAX && cnt < n; ++i)
		{
			if (vis[i] != tc)
			{
				printf("%d ", i), ++cnt;
				for (int j = 0; j < n; ++j) for (int k = j + 1; k < n; ++k)
					vis[min(abs(a[j] - a[k]) + i, MAX)] = tc;
			}
		}
		--tc;
		puts("");
	}
}