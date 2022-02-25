#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX_N = 1e5 + 2;
ll len[MAX_N], a[MAX_N], b[MAX_N];
int m, n;

int find_num(ll idx)
{
	int i = lower_bound(len, len + m, idx) - len;
	if (len[i] == idx && !b[i])return a[i];
	int new_idx = (idx - len[i - 1]) % a[i];
	if (new_idx == 0)new_idx = a[i];
	return find_num(new_idx);

}
int main()
{
	cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int operation; cin >> operation >> a[i];
		b[i] = 0;
		if (operation == 2)
			cin >> b[i];
		ll extra_len = operation == 1 ? 1 : a[i] * b[i];
		len[i] = len[i - 1] + extra_len;
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll d; cin >> d;
		cout << find_num(d) << ' ';
	}
}