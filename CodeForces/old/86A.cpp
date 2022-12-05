#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	string l, r, ans;
	cin >> l >> r;
	int n = l.size(), m = r.size();
	for (int i = n; i < m; ++i)
		l.insert(l.begin(), '0');
	bool large = r[0] > '4';
	if (large)
	{
		if (l[0] >= '5') ans = l;
		else ans = string(m, '0'), ans[0] = '5';
	}
	else
	{
		if (r[0] <= '4') ans = r;
		else ans = string(m, '9'), ans[0] = '4';
	}
	ll s = stoll(ans);
	ll mirror = 0;
	for (int i = 0; i < m; ++i)
		mirror = mirror * 10 + '9' - ans[i];
	cout << s * mirror << endl;
	
}