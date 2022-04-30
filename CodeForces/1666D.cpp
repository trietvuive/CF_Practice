#include<bits/stdc++.h>
using namespace std;
string a, b;
int use[500];
int main() {
	int n; cin >> n;
	while (n--) {
		cin >> a >> b;
		memset(use, 0, sizeof use);
		int n = a.size() - 1, m = b.size() - 1;
		for (int i = n; i >= 0; --i)
		{
			if (a[i] == b[m] && !use[a[i]]) --m;
			else use[a[i]] = 1;
			if (m<0) break;
		}
		if (m < 0) cout << "YES\n";
		else cout << "NO\n";
	}
}