#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		if (a == 1)
			n = (n - 1) % b;
		for (ll i = 1; i <= n && a != 1; i *= a)
			if ((n - i) % b == 0) n = 0;
		if (n == 0)cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}