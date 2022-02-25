#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int MAX_N = 1e5 + 2;

ll a[MAX_N], n, m, b[MAX_N], cnt, ans = 1;
unordered_map<ll, ll> mp;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i], ++mp[a[i]];
	for (int i = 0; i < n; ++i) cin >> b[i], ++mp[b[i]], cnt += (a[i] == b[i]);
	cin >> m;

	for (const auto& pair : mp)
	{
		for (int j = 1; j <= pair.second; ++j)
		{
			ll x = j;
			while (cnt && x % 2 == 0) x /= 2, --cnt;
			ans = (ans * x) % m;
		}
	}
	cout << ans << endl;

}