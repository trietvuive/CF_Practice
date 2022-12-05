#include<bits/stdc++.h>

using namespace std;

int dsu[1000005];

int get_leader(int i) {
	if (dsu[i] == i) return i;
	return dsu[i] = get_leader(dsu[i]);
}

void merge(int i, int j) {
	int leader_i = get_leader(i);
	int leader_j = get_leader(j);
	dsu[leader_i] = leader_j;
}

void solve() {
	int n, k; cin >> n >> k;
	for(int i = 0; i <= n; i++) dsu[i] = i;

	for(int i = 0; i < k; ++i) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}

	for(int i = 1; i <= n; ++i) {
		if(get_leader(i) != get_leader(n+1 - i)) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
