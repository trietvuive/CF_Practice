#include<bits/stdc++.h>
using namespace std;

int dsu[102], perm[102], fav[102];

int get_set(int i)
{
	return i == dsu[i] ? i : dsu[i] = get_set(dsu[i]);
}

void union_set(int i, int j) {
	dsu[get_set(i)] = get_set(j);
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> perm[i], dsu[i] = i;
	for (int i = 1; i <= n; ++i)
		cin >> fav[i];
	for (int i = 1; i <= n; ++i)
	{
		if (i - fav[i] >= 1)
			union_set(i, i - fav[i]);
		if (i + fav[i] <= n)
			union_set(i, i + fav[i]);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (get_set(i) != get_set(perm[i]))
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}