#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int ar[MAX_N];
#define ll long long
int main()
{
	stack<int> s;
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", ar + i);
	int query_n; scanf("%d", &query_n);
	ll first = 0;
	for (int i = 0; i < query_n; ++i)
	{
		int w, h;
		scanf("%d %d", &w, &h);
		cout << (first = max(first, (ll)ar[w - 1])) << endl;
		first += h;
	}
}