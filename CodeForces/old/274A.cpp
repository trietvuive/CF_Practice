#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
const int MAX_N = 1e5 + 2;
int ar[MAX_N];
int main()
{
		int n, k;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < n; ++i)
			cin >> ar[i];
		sort(ar, ar + n);
		int cnt = 0;
		unordered_set<int> s;
		for (int i = 0; i < n; ++i)
		{
			if (ar[i] % k != 0 || s.find(ar[i] / k) == s.end())
				++cnt, s.insert(ar[i]);
		}
		printf("%d", cnt);
}