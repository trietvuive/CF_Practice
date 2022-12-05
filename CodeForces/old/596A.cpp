#include<bits/stdc++.h>
using namespace std;
int x[4], y[4];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	if (n == 1 ||
	   (n == 2 && (x[0] == x[1] || y[0] == y[1])))
		cout << -1 << endl;
}