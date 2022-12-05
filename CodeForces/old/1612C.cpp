#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int tc; cin >> tc;
	while (tc--)
	{
		ll k, x;
		cin >> k >> x;
		ll left = 0, right = 2*k-1;
		while (left < right)
		{
			ll mid = left + (right - left) / 2;
			ll msg = mid <= k ? mid * (mid + 1) / 2 : k*(k+1)/2 + (k-1 + 2*k - mid)*(mid-k) / 2;
			if (msg == x)
			{
				left = mid;
				break;
			}
			else if(msg < x)
				left = mid + 1;
			else
				right = mid;
		}
		cout << left << endl;
	}
}