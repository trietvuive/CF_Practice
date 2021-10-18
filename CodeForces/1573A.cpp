#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		string s; cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); ++i)
			ans += (s[i] != '0' && i != s.size() - 1) + s[i] - '0';
		cout << ans << endl;
	}
}