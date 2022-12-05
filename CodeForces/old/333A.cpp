#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n; cin >> n;
	ll div = 3;
	while (n % div == 0) div *= 3;
	cout << (n / div) + 1 << endl;
}