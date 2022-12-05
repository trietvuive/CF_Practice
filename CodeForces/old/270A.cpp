#include<bits/stdc++.h>
using namespace std;

// x = 180(n-2)/n
// x*n = 180n - 360
// x*n + 360 = 180n
// x + 360/n = 180
int main() {
	int tc; cin >> tc;
	while (tc--) {
		int x; cin >> x;
		if (360 % (180 - x))
			cout << "NO\n";
		else cout << "YES\n";
	}
}