/*#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, k;
	cin >> n >> t >> k;
	int left = 1, right = n;
	while (left < right)
	{
		int mid = (right + left - 1) / 2;
		cout << "? " << left << " " << mid << endl;
		int sum; cin >> sum;
		int zero_count = (mid - left + 1) - sum;
		if (k > zero_count)k -= zero_count, left = mid + 1;
		else right = mid;
	}
	cout << "! " <<left << endl;
}
*/