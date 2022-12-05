#include<bits/stdc++.h>
const double pi = 3.14159265358979323846;
using namespace std;

double radii[102];

int main() {
	int n; cin >> n;
	double ans = 0;
	for (int i = 1; i <= n; ++i)
		cin >> radii[i];
	sort(radii, radii + n + 1);
	for (int i = n; i > 0; i -= 2)
		ans += pi * radii[i] * radii[i] - pi * radii[i - 1] * radii[i - 1];
	cout.precision(20);
	cout << ans << endl;

}