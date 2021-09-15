#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll total_items = 0, total_cost = 0;
	priority_queue < pair < ll, ll >> pq;
	int n;
	cin >> n;
	while (n--)
	{
		ll a, b;
		cin >> a >> b;
		pq.push({ b,a });
		total_items += a;
	}
	while (!pq.empty())
	{
		pair<ll, ll> p = pq.top(); pq.pop();
		ll item = max((ll) 0, min(p.second, total_items - p.first));
		total_cost += item;
		total_items-= item;
	}
	total_cost += total_items * 2;
	cout << total_cost << endl;

}
