#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll prefix[1002][1002];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		memset(prefix, 0, sizeof prefix);
		ll n, q, h, w; cin >> n >> q;
		for(int i = 0; i < n; ++i)
			cin >> h >> w, prefix[h][w] += h*w;
		for(int i = 1; i <= 1000; ++i)
			for(int j = 1; j <= 1000; ++j)
				prefix[i][j] += prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];

		for(int i = 0; i < q; ++i) {
			int hs,ws,hb,wb; cin >> hs >> ws >> hb >> wb;
			--hb, --wb;

			ll ans = prefix[hb][wb] - prefix[hs][wb] - 
					prefix[hb][ws] + prefix[hs][ws];
			cout << ans << '\n';
		}
	}
}
