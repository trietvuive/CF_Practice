#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll N, M, d[300005];

namespace Combo {
    const int MOD = 998244353;

    vector<ll> fact = {1};
    vector<ll> inv = {1};

    ll binexp(ll a, ll b) {
        if (b == 0) return 1ll;
        if (b == 1) return a % MOD;
        if (b % 2) return (a * binexp(a, b - 1)) % MOD;
        return binexp((a*a)%MOD, b/2);
    }

    void extend(int n) {
        while ((int) fact.size() < n + 1) {
            fact.push_back(fact.back() * fact.size() % MOD);
            inv.push_back(binexp(fact.back(), MOD - 2));
        }
    }

    ll choose(ll a, ll b) {
        if (a < b) return 0;
        extend(a);
        ll res = (fact[a] * inv[b]) % MOD;
        res *= inv[a - b]; res %= MOD;
        return res;
    }
};

using namespace Combo;

ll mul(ll a, ll b) {
    return a * b % MOD;
}

ll add(ll a, ll b) {
    if (a + b >= MOD) return a + b - MOD;
    return a + b;
}

ll color(ll a, ll num_colors) {
    return binexp(mul(num_colors, num_colors - 1), a);
}

ll count_pairs() {
	ll pair = 0, total = 0, e;
	set<ll> s;
	for(int i = 1; i <= N; ++i)
		s.insert(total += d[i]);
	if(total % 2) return 0;
	for(ll i : s) 
		if(s.find(i + total/2) != s.end()) ++pair;
	return pair;
}

void solve() {
	cin >> N >> M;
	for(int i = 1; i <= N; ++i) cin >> d[i];

	ll p = count_pairs();
	ll ans = 0;
	extend(1e5 + 1);

    for (int i = 0; i <= min(M,p); ++i) {
        // i pairs have the same color endpoint
        ll same_diameters = mul(choose(p, i), mul(choose(M,i), fact[i]));
        ll dif_diameters = color(p-i, M-i);
        ll rest_points = binexp(max(0ll, M-i), N-2*p);

        /* cout << rest_points << ' ' << dif_diameters << ' ' << same_diameters << endl; */
        /* cout << dif_diameters << ' ' << same_diameters << endl; */
        /* cout << rest_points << endl; */
        /* cout << mul(rest_points, mul(same_diameters, dif_diameters)) << endl; */
        ll x = mul(rest_points, mul(same_diameters, dif_diameters));
        ans = add(ans, x);
    }

    cout << ans << endl;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	solve();
}
