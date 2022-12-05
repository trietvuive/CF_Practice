#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll sum_up = 0, sum_down = 0;
		
		cin >> n;
		vector<int> up;
		for (int i = 0; i < n; ++i)
		{
			int num; cin >> num;
			up.push_back(num), sum_up += num * (i!= 0);
		}
		up.push_back(0);
		ll ans = sum_up;
		for (int i = 0; i < n; ++i)
		{
			int down; cin >> down;
			sum_down += down, sum_up -= up[i+1];
			ans = min(ans, max(sum_down, sum_up));
		}
		cout << ans << endl;
	}
}
