#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e4 + 2;
#define ll long long
int get_sum(int i, int j)
{
	int res1, res2;
	printf("or %d %d\n", i, j);
	cout.flush();
	cin >> res1;
	printf("and %d %d\n", i, j);
	cout.flush();
	cin >> res2;
	return res1 + res2;
}
int main() {
	int n, k;
	cin >> n >> k;

	ll sum_ab = get_sum(1, 2), sum_bc = get_sum(2, 3), sum_ac = get_sum(1, 3);
	ll a = (sum_ab + sum_bc + sum_ac) / 2 - sum_bc, b = sum_ab - a, c = sum_ac - a;

	priority_queue<int>pq;
	pq.push(a), pq.push(b), pq.push(c);
	while (pq.size() > k)
		pq.pop();

	for (int i = 4; i <= n; ++i) {
		int element = get_sum(1, i) - a;
		if (pq.size() == k && element >= pq.top())continue;
		else pq.push(element);
		if (pq.size() > k)pq.pop();
	}
	cout << "finish " << pq.top() << endl;
}
