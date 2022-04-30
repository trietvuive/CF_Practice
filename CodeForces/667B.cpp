#include<bits/stdc++.h>
using namespace std;
int mx, sm;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int element; cin >> element;
		mx = max(mx, element), sm += element;
	}
	cout << max(0, mx * 2 - sm + 1) << endl;
}