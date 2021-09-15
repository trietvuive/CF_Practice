#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll left, right;
		cin >> left >> right;
		ll left_change = 0, right_change = 0;
		ll base_10 = 1;
		while (base_10 <= right)
		{
			left_change += left / base_10, right_change += right / base_10;
			base_10 *= 10;
		}
		cout << right_change - left_change << endl;
	}

}
