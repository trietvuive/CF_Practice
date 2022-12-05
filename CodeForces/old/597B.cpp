#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
const int MAX_N = 5e5 + 2;

pii ar[MAX_N];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i].first >> ar[i].second;
	sort(ar, ar + n, [](const pii& a, const pii& b)
		{
			return a.second < b.second;
		});
	int res = 0, end = 0;
	for (int i = 0; i < n; ++i)
		if (ar[i].first > end)
			++res, end = ar[i].second;
	cout << res << endl;
}