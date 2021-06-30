/*#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n, k, x;
	cin >> n >> k >> x;
	vector<ll> students;
	priority_queue<ll> gaps;
	while (n--)
	{
		ll a;
		cin >> a;
		students.push_back(a);
	}
	sort(students.begin(), students.end());
	for (int i = 0; i < students.size() - 1; ++i)
	{
		ll gap = students[i + 1] - students[i];
		if (gap > x)
			gaps.push(-(gap % x == 0 ? gap / x - 1 : gap / x));
	}
	while (!gaps.empty() && k + gaps.top() >= 0)
	{
		k += gaps.top(); gaps.pop();
	}
	cout << gaps.size() + 1 << endl;

}
*/