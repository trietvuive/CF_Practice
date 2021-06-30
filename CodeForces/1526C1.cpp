/*#include<bits/stdc++.h>
#define ll long long
const int MAXN = 200002;
ll ar[MAXN];
using namespace std;
int main()
{
	priority_queue<int> pq;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i];
	ll potions = 0;
	ll health = 0;
	for (int i = 0; i < n; ++i)
	{
		if (ar[i] >= 0) health += ar[i], ++potions;
		else
		{
			if (health + ar[i] >= 0)
				health += ar[i], ++potions, pq.push(-ar[i]);
			else
				if (!pq.empty() && pq.top() > -ar[i])
					health += pq.top() + ar[i], pq.pop(), pq.push(-ar[i]);
		}
	}
	cout << potions << endl;
}
*/