#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll k, a, b; cin >> k >> a >> b;
	a = a % k ? k * (a / k + (a > 0)) : a;
	b = b % k ? k * (b / k - (b < 0)) : b;
	cout << (b - a) / k + 1 << endl;
}