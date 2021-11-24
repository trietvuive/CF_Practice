#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 1e5 + 3;
int temp[MAX_N], costs[MAX_N];

int main()
{
	auto comp = [](int idx_a, int idx_b) { 
		return costs[idx_a] == costs[idx_b] ? idx_a < idx_b : costs[idx_a] < costs[idx_b]; 
	};
	map<int, int, decltype(comp)> dishes(comp);
	int n, m;
	ll total_amount = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", temp + i), total_amount += temp[i];
	for (int i = 1; i <= n; ++i)
	{
		int cost; scanf("%d", &cost);
		costs[i] = cost;
		dishes[i] = temp[i];
	}

	for (int i = 0; i < m; ++i)
	{
		ll type, amount, total_cost = 0;
		cin >> type >> amount;
		total_amount -= amount;
		if (total_amount < 0) {
			printf("0\n");
			continue;
		}
		while (amount > 0)
		{
			if (dishes.find(type) != dishes.end() && dishes[type] > 0)
			{
				total_cost += min(amount, (ll)dishes[type]) * (ll)costs[type];
				amount -= dishes[type];
				if (amount >= 0)dishes.erase(type);
				else dishes[type] = -amount;
			}
			if(dishes.size() > 0)
				type = dishes.begin()->first;
		}
		cout << total_cost << endl;
	}
}