#include<bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k < n || k > 26*n) {
		cout << "impossible" << endl;
		return;
	}

	while(k > n) {
		n--;
		if(k - 26 >= n) {
			cout << "z";
			k -= 26;
		} else {
			cout << (char)('a' + k - n - 1);
			k = n;
		}
	}
	while(n--) {
		cout << "a";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	solve();
}
