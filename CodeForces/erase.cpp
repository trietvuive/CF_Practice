#include<bits/stdc++.h>

using namespace std;

void solve() {
	int n; string a,b; cin >> n >> a >> b;
	for(int i = 0; i < a.size(); ++i) {
		if((a[i] != b[i]) ^ (n & 1)) {
			cout << "Deletion failed" << endl;
			return;
		}
	}
	cout << "Deletion succeeded" << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
