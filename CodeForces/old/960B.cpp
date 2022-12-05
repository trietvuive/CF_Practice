#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e3 + 2;
#define ll long long
int diff[MAX_N];
int main()
{
	int n, k1, k2;
	ll sum = 0, ans = 0;
	scanf("%d %d %d", &n, &k1, &k2);
	for (int i = 0; i < n; ++i)
		scanf("%d", diff+i);
	for (int i = 0; i < n; ++i)
	{
		int element; scanf("%d", &element);
		diff[i] = abs(diff[i] - element);
		sum += diff[i];
	}
	sort(diff, diff + n);
	sum -= (k1 + k2);
	for (int i = n - 1; i >= 0; --i)
	{
		//if sum <= everything on the left * the smallest element, start chopping
		if (sum <= (i + 1) * diff[i])
		{
			ll low = sum / (i + 1), high = low + 1;
			ll high_cnt = low == 0 ? sum : sum % low, low_cnt = (i + 1) - high_cnt;
			ans += low * low * low_cnt, ans += high * high * high_cnt;
			break;
		}
		//greedy won't have enough to change this, leave it alone
		else
			ans += diff[i] * diff[i], sum -= diff[i];
	}
	if (sum < 0)cout << -(sum % 2) << endl;
	else
		cout << ans <<"\n";

}