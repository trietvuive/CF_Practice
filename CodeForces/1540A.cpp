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
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		if (n <= 2)
		{
			cout << 0 << endl;
			continue;
		}
		sort(v.begin(), v.end());
		ll result = 0;
		ll left_idx = 0, right_idx = n - 1, left_cm = 0, right_cm = 0;
		while (left_idx < right_idx)
		{
			right_cm += v[right_idx--], left_cm += v[left_idx++];
			ll difference = right_cm - left_cm;
			if (left_idx == 1)result -= difference;
			else if (right_idx == left_idx - 1)result -= difference;
			else result -= difference * 2;
		}
		cout << result << endl;
	}
}
