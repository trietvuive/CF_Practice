#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ar[50002];
int main()
{
	ll n, sm = 0; cin >> n;
	ll total = 0;
	for (int i = 0; i < n; ++i)
		cin >> ar[i], sm += ar[i];
	ll avg = sm / n;
	for (int i = 0; i < n-1; ++i)
	{
		total += abs(ar[i] - avg);
		ar[i + 1] += ar[i] - avg;
	}
	cout << total << endl;
}