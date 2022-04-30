#include<bits/stdc++.h>
using namespace std;
double loc[102];
int main() {
	double n, vb, vs, x, y;
	cin >> n >> vb >> vs;
	for (int i = 1; i <= n; ++i)
		cin >> loc[i];
	cin >> x >> y;
	double mn = INT_MAX;
	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		double tm = sqrt(y * y + (x - loc[i]) * (x - loc[i])) / vs + loc[i] / vb;
		if (tm <= mn)
			mn = tm, ans = i;
	}
	cout << ans << endl;
}