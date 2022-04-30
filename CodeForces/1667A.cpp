#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6;
int n;
ll a[N], f[N], c, x, A = 1e18;

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i) {
		f[i] = c = 0;
		for (int j = i - 1; j; --j)
			x = f[j + 1] / a[j] + 1, f[j] = x * a[j], c += x;
		for (int j = i + 1; j <= n; ++j)
			x = f[j - 1] / a[j] + 1, f[j] = x * a[j], c += x;
		A = min(A, c);
	}
	cout << A << endl;
}