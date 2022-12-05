#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--) {
		int n, k; cin >> n >> k;
		int left = 0, right = n - 1;
		string s; cin >> s;
		for (; left < right; ++left, --right)
			if (s[left] != s[right])break;
		cout << (k == 0 || left >= right ? 1 : 2) << endl;
	}
}