#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n,m,k,r,c; cin >> n >> m;
	printf("? %d %d\n", 1, 1);
	fflush(stdout);
	cin >> k;

	++k;
	r = min(k,n), c = min(k,m);
	printf("? %d %d\n", r, c);
	fflush(stdout);
	
	cin >> k;
	printf("? %d %d\n", max(1, r-k), c);
	fflush(stdout);

	int temp;
	cin >> temp;
	if(temp == 0) printf("! %d %d\n", r-k, c);
	else printf("! %d %d\n", r, c-k);
	fflush(stdout);
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

