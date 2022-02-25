#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll digit_sum(ll start, ll end)
{
	ll last = min(9ll,end), cnt = 1, sum = 0;
	while (last < start) last = min(last * 10 + 9, end), ++cnt;
	while (start <= end)
	{
		sum += (last - start + 1) * cnt++;
		start = last + 1;
		last = min(last * 10 + 9, end);
	}
	return sum;
}
int main()
{
	ll w, m, k; 
	cin >> w >> m >> k;
	ll left = m-1, right = m + w;
	while (left < right)
	{
		ll mid = left + (right - left + 1) / 2;
		ll sum = digit_sum(m, mid);
		if (sum > w / k) right = mid - 1;
		else left = mid;
	}
	cout << left - m + 1 << endl;
}