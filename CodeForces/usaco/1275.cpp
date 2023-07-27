#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	s = ' ' + s;

	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) 
		cin >> a[i];

	int h_leader = n, g_leader = n;
	int last_h = -1, last_g = -1;

	for(int i = 1; i <= n; ++i)
		if(s[i] == 'H') last_h = i, h_leader = min(h_leader, i);
		else last_g = i, g_leader = min(g_leader, i);

	if(a[h_leader] < last_h) h_leader = -1;
	if(a[g_leader] < last_g) g_leader = -1;

	int ans = (h_leader != -1) && (g_leader != -1);
	for(int i = 1; i <= n; ++i) {
		if(i == h_leader || i == g_leader) continue;
		if(s[i] == 'H' && i <= g_leader && g_leader <= a[i]) ++ans;
		if(s[i] == 'G' && i <= h_leader && h_leader <= a[i]) ++ans;
	}

	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

