#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 2e5 + 2;
ll ar[MAX_N];
int s[MAX_N], build[MAX_N];
int main() {
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n; cin >> n;
		for (int i = 1; i <= n; ++i)
			cin >> ar[i], s[i] = i;
		sort(s + 1, s + n + 1, [](int a, int b)
			{
				return ar[a] > ar[b];
			});
		ll sm = 0;
		for (ll i = 1; i <= n; ++i)
			sm += (i + 1)/2 * ar[s[i]];
		cout << sm*2 << endl;

		for (int i = 1; i <= n; ++i)
			build[s[i]] = (i % 2 ? 1 : -1) * (i+1) / 2;
		for (int i = 0; i <= n; ++i)
			cout << build[i] << " ";
		cout << endl;
	}
}