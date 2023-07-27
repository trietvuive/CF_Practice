#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

constexpr int MAXN = 2e5 + 10;
int segtree[4 * MAXN], a[MAXN], n, q;

void build(int node, int l, int r) {
	if(l == r) {
		segtree[node] = a[l];
		return;
	}

	int mid = (l + r) / 2;
	build(node * 2, l, mid);
	build(node * 2 + 1, mid + 1, r);

	segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
}

void update(int val, int left = 1, int right = n, int node = 1) {
	if(left == right) {
		segtree[node] -= val;
		cout << left << ' ';
		return;
	}

	int mid = (left + right) / 2;
	if(segtree[node*2] >= val) 
		update(val, left, mid, node*2);
	else
		update(val, mid+1, right, node*2+1);

	segtree[node] = max(segtree[node*2], segtree[node*2+1]);
}

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);

	for(int i = 1; i <= q; ++i) {
		int x; cin >> x;
		if(segtree[1] < x) 
			cout << 0 << ' ';
		else 
			update(x);
	
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

