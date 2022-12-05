#include<bits/stdc++.h>
using namespace std;
int ar[102];

int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n, l, r, k, pointer = 0, ans = 0;
		cin >> n >> l >> r >> k;
		for (int i = 0; i < n; ++i)
		{
			int element; cin >> element;
			if (element >= l && element <= r)
				ar[pointer++] = element;
		}
		sort(ar, ar + pointer);
		for (int i = 0; i < pointer; ++i)
			if (k - ar[i] >= 0)
				k -= ar[i], ++ans;
			else
				break;
		cout << ans << endl;
	}
}