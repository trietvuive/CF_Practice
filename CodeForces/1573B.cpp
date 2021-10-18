#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int min_idx[MAX_N];
int main()
{
	int tc; cin >> tc;
	while (tc-- > 0)
	{
		int n; cin >> n;
		int min_element = n;
		for (int i = 0; i < n; ++i)
		{
			int element; cin >> element;
			element /= 2;
			while (min_element > element)
				min_idx[min_element--] = i;
		}
		int ans = 2 * n;
		for (int i = 0; i < n; ++i)
		{
			int element; cin >> element;
			ans = min(ans, i + min_idx[element / 2]);
		}
		cout << ans << endl;
	}
}