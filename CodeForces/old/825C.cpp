#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1e3 + 2;
int ar[MAX_N];
int main()
{
	int n, k, ans = 0;
	cin >> n >> k;
	int max_rating = 2 * k;
	for (int i = 0; i < n; ++i)cin >> ar[i];
	sort(ar, ar + n);
	for (int i = 0; i < n; ++i)
	{
		while (ar[i] > max_rating)++ans, max_rating *= 2;
		max_rating = max(max_rating, ar[i] * 2);
	}
	cout << ans << endl;

}