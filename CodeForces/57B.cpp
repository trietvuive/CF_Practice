#include<bits/stdc++.h>
#define ll long long
const int MAX_N = 1e5 + 2;
int l[MAX_N], r[MAX_N], s[MAX_N], n, m, k, pos;
using namespace std;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < m; ++i)
		scanf("%d %d %d", l + i, r + i, s + i);
	ll sm = 0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &pos);
		for (int j = 0; j < m; ++j)
			if (l[j] <= pos && pos <= r[j])
				sm += pos - l[j] + s[j];
	}
	cout << sm << endl;
}