#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 3e5 + 2;
int ar[MAX_N];
int main()
{
	int tc;
	cin >> tc;
	while (tc-- > 0)
	{
		int n, q; cin >> n >> q;
		for (int i = 1; i <= n; ++i) {
			char c; cin >> c;
			ar[i] = ar[i-1] + (i & 1 ? 1 : -1) * (c == '+' ? 1 : -1);
		}
		for (int i = 0; i < q; ++i)
		{
			int left, right; cin >> left >> right;
			if (ar[right] == ar[left - 1]) cout << 0 << endl;
			else if ((right - left + 1) & 1)cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
}