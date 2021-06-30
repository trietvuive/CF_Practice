/*#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		ll sum = 0;
		cin >> n;
		vector<int> v(n), sorted(n);
		for (int i = 0; i < n; ++i)
			cin >> v[i], sorted[i] = v[i];
		sort(sorted.begin(), sorted.end());
		int tipping_point = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			sum += sorted[i];
			if (sum < sorted[i + 1])
				tipping_point = i+1;
		}
		cout << n - tipping_point << endl;
		for (int i = 0; i < n; i++)
		{
			if (v[i] >= sorted[tipping_point])
				cout << i+1 << " ";
		}
		cout << endl;
	}
}
*/