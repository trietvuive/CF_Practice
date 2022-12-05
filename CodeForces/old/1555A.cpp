#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t;
	cin >> t;
	while (t--)
	{
		ll n; cin >> n;
		n += n % 2;
		cout << (n<=6 ? 15 : n*5/2) << endl;
	}
}
