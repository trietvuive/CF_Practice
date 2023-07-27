#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

/* 1/b + 1/c = 4/n - 1/a = (4a-n)/(an)
 * (b+c)/(bc) = (4a-n)/(an), > 0
 * (b+c)(an) = (4a-n)(bc), > 0
 *
 * ????????? assuming if latter doesn't exist, then former doesn't exist
 * let const x = 4a-n, y = an
 * (b+c) = a, bc = y
 * b = a-c, c(a-c) = y
 * -c^2 + ac = y
 * c^2 + -ac + y = 0
 * c = (a + sqrt(a^2 - 4y))/2
 * iterate through a from 1 to INF, find b and c
 */

bool check_root_int(ll x) {
	ll root = sqrt(x);
	return root * root == x;
}

void solve() {
	ll i,n; cin >> i >> n;
	ll a=1,b,c;
	while(true) {
		ll x = 4*a-n, y = a*n;
		if(!check_root_int(a*a - 4*y)) ++a;
		else {
			c = (a + sqrt(a*a - 4*y));
			if(c % 2 || c/2 >= a) ++a;
			else {
				c /= 2;
				b = a-c;
				cout << a << ' ' << b << ' ' << c << endl;
				return;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

