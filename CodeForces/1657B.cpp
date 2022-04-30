#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc--) {
		int n, B, x, y; cin >> n >> B >> x >> y;
		int start = 0;
		ll sm = 0;
		for (int i = 0; i < n; ++i)
			start = start + x <= B ? start + x : start - y,
			sm += start;
		cout << sm << endl;
	}
}