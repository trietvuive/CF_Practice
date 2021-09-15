#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
using namespace std;
const ll MAX = 10e15+3;
const ll PRIME_MAX = 500;
bool all_sum[MAX];
bool constructable(ll product, ll sum, const vector<int>& counter)
{
	unordered_map<ll, ll>prime_counter;
	for (ll i = 0; i <= sum; i++)
	{
		if (counter[i])
		{
			while (product % i == 0)
			{
				++prime_counter[i], product /= i, sum -= i;
				if (sum <= 0)
					return false;
			}
		}
	}
	if (sum != 0 || product != 1)
		return false;
	for (const pair<ll, ll> &p : prime_counter)
	{
		if (p.second > counter[p.first])
			return false;
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	for (int case_no = 1; case_no <= t; case_no++)
	{
		vector<int> counter(PRIME_MAX, 0);

		ll max_product = 0;
		ll M, sum = 0;
		cin >> M;
		for (ll i = 0; i < M; i++)
		{
			ll prime, count;
			cin >> prime >> count;
			counter[prime] = count;
			for (ll p = sum; p > 0; p--)
			{
				if (all_sum[p])
				{
					for (ll j = 0; j < count; j++)
						all_sum[p + prime * j] = true;
				}
			}
			sum += prime * count;
			for (int p = 0; p < count; p++)
				all_sum[prime * p] = true;
		}
		cout << "Hey I'm here!" << endl;
		for (ll i = sum; i > 0; i--)
			if (constructable(i, sum - i,counter))
			{
				max_product = i;
				break;
			}
		cout << "Case #"<<case_no << ": " << max_product << endl;
	}
}