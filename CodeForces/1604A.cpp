#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		int mx = INT_MIN;
		for (int i = 1; i <= n; ++i)
		{
			int element; cin >> element;
			mx = max(mx, element - i);
		}
		cout << mx << endl;
	}
}