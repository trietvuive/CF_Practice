#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 5;
int f[MAX_N];
set<int> v[MAX_N * 4 + 5];
char a[MAX_N * 4 + 5];
int main()
{
	int t; scanf("%d", &t);
	while (t-- > 0)
	{
		int n, q;
		scanf("%d%d", &n, &q);
		scanf("%s", a + 1);
		for (int i = 1; i <= n; ++i) {
			f[i] = f[i - 1] + (a[i] == '+' ? 1 : -1) * (i & 1 ? 1 : -1);
			v[f[i] + f[i - 1] + MAX_N * 2].clear();
		}
		for (int i = 1; i <= n; ++i)
			v[f[i] + f[i - 1] + MAX_N * 2].insert(i);
		while (q--)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			if (f[r] == f[l - 1])printf("0\n");
			else
			{
				if ((r - l) & 1)printf("2\n%d ", l), ++l;
				else printf("1\n");
				printf("%d\n", *v[f[l - 1] + f[r] + MAX_N * 2].lower_bound(l));
			}
		}
	}
}