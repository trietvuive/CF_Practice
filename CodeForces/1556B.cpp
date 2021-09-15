#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 1e5 + 2;
int n, ar[MAX_N];
ll solve(int first)
{
	ll swap = 0;
	int idx_zero = first == 0 ? 0 : 1;
	int idx_one = first == 1 ? 0 : 1;
	for (int i = 0; i < n; ++i)
		if (ar[i] == 0)swap += abs((i - idx_zero)), idx_zero += 2;
		else swap += abs((i - idx_one)), idx_one += 2;
	return swap / 2;
}
int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		cin >> n;
		int zero_count = 0 , one_count = 0;
		for (int i = 0; i < n; ++i)
			cin >> ar[i], ar[i] %= 2, zero_count += ar[i] == 0, one_count += ar[i] == 1;
		if (abs(zero_count - one_count) > 1)
		{
			cout << -1 << endl; continue;
		}
		ll ans = 0;
		if (zero_count > one_count)
			ans = solve(0);
		else if (one_count > zero_count)
			ans = solve(1);
		else ans = min(solve(0), solve(1));
		cout << ans << endl;
	}
}
