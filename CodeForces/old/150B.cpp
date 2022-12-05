#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;
#define ll long long
const ll MOD = 1e9 + 7;
int dsu[2002];

ll pow_mod(ll a, ll b)
{
	if (b == 0)return 1;
	ll half = pow_mod(a, b / 2);
	return ((half * half) % MOD * (b % 2 ? a : 1)) % MOD;
}

int get_set(int i)
{
	return dsu[i] == i ? i : dsu[i] = get_set(dsu[i]);
}

void union_set(int i, int j)
{
	int a = get_set(i), b = get_set(j);
	if (a != b)
		dsu[a] = b;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		dsu[i] = i;

	int substr_count = min(n - k + 1, k);
	for (int i = 0; i < n; ++i)
		for (int cnt = 0, j = abs(i - k + 1); cnt < min(substr_count, i + 1) && j < n; ++cnt, j += 2)
			union_set(i, j);

	unordered_set<int> diff;
	for (int i = 0; i < n; ++i)
		diff.insert(get_set(i));
	int ans = pow_mod(m, (ll)diff.size());
	cout << ans << endl;

}