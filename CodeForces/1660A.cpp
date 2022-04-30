#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int a, b; cin >> a >> b;
		if (a == 0) cout << 1 << endl;
		else cout << b * 2 + a + 1 << endl;
	}
}