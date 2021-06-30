/*#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll N, M, a, b, d;
		cin >> N >> M >> a >> b >> d;
		ll home_duration = (N + b - a) % N;
		ll home_start = (b + d) % N;
		if (home_start + home_duration < N-M)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
*/