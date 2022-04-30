#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	ll prod = sqrt(a * b * c);
	cout << 4 * (prod / a + prod / b + prod / c) << endl;
}