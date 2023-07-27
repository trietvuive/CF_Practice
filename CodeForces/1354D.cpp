#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

vector<int> a, k;

int count_le(int x) {
	int res = 0;
	for(int i : a)
		res += i <= x;

	for(int i : k) {
		if(i > 0 && i <= x)
			res++;
		else if(i < 0 && -i <= res)
			res--;
	}
	return res;
}

void solve() {
	int n, q; cin >> n >> q;
	a.resize(n);
	k.resize(q);

	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < q; i++) cin >> k[i];

	if(count_le(1e9) == 0) {
		cout << "0" << endl;
		return;
	}

	int l = 1, r = 1e6;
	while(l < r) {
		int m = (l + r) / 2;
		if(count_le(m) > 0)
			r = m;
		else
			l = m + 1;
	}
	cout << l;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

