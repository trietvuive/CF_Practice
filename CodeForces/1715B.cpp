#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		ll n,k,b,s; cin >> n >> k >> b >> s;
		//n within [b*k, b*k + n*(k-1)]
		if(s < b*k || s > (b*k + n*(k-1)))
			cout << -1 << "\n";
		else {
			cout << min(s, b*k + (k-1)) << ' ';
			s -= min(s, b*k + (k-1));
			for(int i = 1; i < n; ++i) {
				cout << min(s, k-1) << ' ';
				s -= min(s, k-1);
			}
			cout << '\n';
		}
	}
}
