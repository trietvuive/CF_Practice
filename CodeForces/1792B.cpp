#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int a,b,c,d; cin >> a >> b >> c >> d;
	int diff = abs(b - c);
	int jokes = a + 2 * min(b,c) + min(a+1, diff + d); 

	if(a == 0) cout << 1 << '\n';
	else cout << jokes << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc; cin >> tc;
	while(tc--) solve();
}

