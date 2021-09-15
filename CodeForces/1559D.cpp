#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 1e5 + 2;
int dsa[MAX_N], dsb[MAX_N];
int get_head(int x, int* dsu)
{
	return dsu[x] == x ? x : dsu[x] = get_head(dsu[x], dsu);
}
int main() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i = 1; i <= n; ++i)dsa[i] = dsb[i] = i;
	for (int i = 1, x, y; i <= m1; ++i)cin >> x >> y, dsa[get_head(x, dsa)] = get_head(y, dsa);
	for (int i = 1, x, y; i <= m2; ++i)cin >> x >> y, dsb[get_head(x, dsb)] = get_head(y, dsb);
	cout << n - max(m1, m2)-1 << endl;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{
			if (get_head(i, dsa) != get_head(j, dsa) && get_head(i, dsb) != get_head(j, dsb))
			{
				cout << i << " " << j << endl;
				dsa[get_head(i, dsa)] = get_head(j, dsa);
				dsb[get_head(i, dsb)] = get_head(j, dsb);
			}
		}
	}

}
