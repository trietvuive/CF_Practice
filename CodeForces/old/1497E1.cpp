#include<iostream>
#include<unordered_set>
#include<vector>
#include<unordered_map>

using namespace std;
int main()
{
	unordered_map<int, int>mp;
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, k;
		cin >> n >> k;
		register int ans = 1, st = 1;
		for (register int i = 1, a; i <= n; i++)
		{
			cin >> a;
			for (register int j = 2; j * j <= a; j++)
				while (a % (j * j) == 0)
					a /= (j * j);
			if (mp[a] >= st)
				ans++, st = i;
			mp[a] = i;
		}
		cout << ans << endl;
		mp.clear();
	}
}
