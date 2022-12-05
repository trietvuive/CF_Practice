#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 2;
int main()
{
	map<int, int> cnt;
	int n, mx = 0; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a; cin >> a; ++cnt[a];
	}
	for (auto& pair : cnt)
	{
		if(pair.second >= 2)
			cnt[pair.first + 1] += pair.second / 2;
		pair.second %= 2;
		mx = max(mx, pair.first);
	}


	for (auto& pair : cnt)
		if (pair.second == 1)--mx;

	cout << mx + 1 << endl;
}