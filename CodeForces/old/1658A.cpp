#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n; char c;
		int one = 0, zero = 0, ans = 0;
		for (int i = 0; i < n; ++i) {
			cin >> c;
			if (c == '0' && zero) ans += max(0, 2 - one), one = 0;
			else if (c == '0') one = 0;
			one += c == '1', zero += c == '0';
		}
		cout << ans << endl;
	}
}