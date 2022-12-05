#include<bits/stdc++.h>
using namespace std;
#define ll long long
int rl[502], rw[502], rh[502];
int cost[502];
int main()
{
	int rn; cin >> rn;
	for (int i = 0; i < rn; ++i)
	{
		cin >> rl[i] >> rw[i] >> rh[i];
		cost[i] = INT_MAX;
	}
	int pn; cin >> pn;
	for (int i = 0; i < pn; ++i)
	{
		int l, w, c; cin >> l >> w >> c;
		for (int j = 0; j < rn; ++j)
		{
			if (l < rh[j]) continue;
			int total_width = l / rh[j] * w;
			int perimeter = (rl[j] + rw[j]) * 2;
			int total_rolls = perimeter % total_width ? perimeter / total_width + 1 : 
														perimeter / total_width;
			cost[j] = min(cost[j], total_rolls * c);
		}
	}
	int sm = 0;
	for (int i = 0; i < rn; ++i)
		sm += cost[i];
	cout << sm << endl;
}