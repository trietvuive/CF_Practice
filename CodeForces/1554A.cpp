#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		ll ans = 0, last = 0, curr = 0;
		cin >> last;
		for (int i = 0; i < n - 1; ++i)
		{
			cin >> curr;
			ans = max(ans, last * curr);
			last = curr;
		}
		cout << ans << endl;
	}
}
