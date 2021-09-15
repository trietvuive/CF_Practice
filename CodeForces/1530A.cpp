#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		int mx = 0;
		while (n > 0) mx = max(mx, n % 10), n /= 10;
		cout << mx << endl;
	}
}