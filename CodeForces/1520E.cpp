/*#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--) {
		int n, count = 0; cin >> n;
		string s;
		for (int i = 0; i < n; ++i)
		{
			char c;
			cin >> c;
			s += c;
			if (c == '*')++count;
		}
		if (count == 1 || count == 0)
		{
			cout << 0 << endl;
			continue;
		}
		int middle = count / 2+1, mid_index = -1;
		while (middle)
			if (s[++mid_index] == '*')--middle;
		ll ans = 0;
		for (int i = 0, star_idx = 1; i < n; ++i)
		{
			if (s[i] == '*')
			{
				int landing_index = mid_index + star_idx - (count / 2+1);
				++star_idx, ans += abs(i - landing_index);
			}
		}
		cout << ans << endl;
	}
}
*/