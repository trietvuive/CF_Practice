#include<bits/stdc++.h>
using namespace std;

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		int n, x, element; cin >> n >> x;
		int mn = x+1;
		for (int i = 0; i < n; ++i) {
			cin >> element;
			mn = min(mn, x % element ? max(2, x / element + 1) : x / element);
		}
		cout << mn << endl;
	}
}