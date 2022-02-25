#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int MAX_N = 1e6 + 2;
ll ar[MAX_N], lsum[MAX_N], lmax[MAX_N], rsum[MAX_N], rmax[MAX_N];

int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; ++i)cin >> ar[i];

	lmax[0] = ar[0], rmax[n - 1] = ar[n - 1];
	for (int i = 1; i < n; ++i)
		lmax[i] = max(lmax[i - 1] + 1, ar[i]), lsum[i] = lsum[i - 1] + lmax[i] - ar[i];
	for (int i = n - 2; i >= 0; --i)
		rmax[i] = max(rmax[i + 1] + 1, ar[i]), rsum[i] = rsum[i + 1] + rmax[i] - ar[i];

	ll mx = min(lsum[n-1], rsum[0]);
	for (int i = 0; i < n - 1; ++i)
		mx = min(mx, lsum[i] + rsum[i + 1] + max(0ll, lmax[i] - rmax[i + 1] + 1));

	cout << mx << endl;

}