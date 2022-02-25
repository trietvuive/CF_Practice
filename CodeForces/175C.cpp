#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long,long>
ll n, t, p[102], sm, cur_p;
pll ck[102];

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ck[i].second >> ck[i].first;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		cin >> p[i];
	p[t + 1] = LLONG_MAX, p[0] = 0;
	sort(ck, ck + n);
	int p_idx = 1;
	for (int i = 0; i < n; ++i)
	{
		ll c = ck[i].first, k = ck[i].second;
		sm += p_idx * c * min(k, p[p_idx] - cur_p);
		cur_p += k;
		while (cur_p > p[p_idx])
			++p_idx, sm += p_idx * c * (min(cur_p, p[p_idx]) - p[p_idx - 1]);
	}
	cout << sm << endl;
}