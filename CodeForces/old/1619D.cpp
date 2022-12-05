#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int n, m, t, a[N], b[N];
int main() {
	cin >> t;
	while (t--) {
		int c = 0;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		cin >> m >> n;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j)
				cin >> b[j], a[j] = max(a[j], b[j]);
			sort(b, b + n);
			c = max(c, b[n - 2]);
		}
		cout << min(c, *min_element(a, a + n)) << endl;
	}
}