#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		int sm = 0, element;
		int n; cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> element, sm += element - 1;
		cout << (sm % 2 ? "errorgorn\n" : "maomao90\n");
	}
}