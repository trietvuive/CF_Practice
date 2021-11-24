#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int ar[MAX_N];
int main()
{
	int n, total = 0;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> ar[i], total += ar[i];
	int p = total / n, q = total % n, ans = 0;
	sort(ar, ar + n);
	for (int i = n - 1; i >= 0; --i)
		ans += q > 0 ? abs(ar[i] - p - 1) : abs(ar[i] - p),
		--q;
	cout << ans / 2 << endl;
}