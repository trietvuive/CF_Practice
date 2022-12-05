#include<bits/stdc++.h>
using namespace std;
int i, x, y, c[4];
int main() {
	for (; i < 4; i++)cin >> c[i], c[i]--;
	cout << "32 50\n";
	for (i = 0; i < 1600; i++) {
		x = i / 400;
		y = (x + 1) % 4;
		if (i % 2 == 0 && i / 50 % 2 == 0 && c[y]) x = y, --c[y];
		cout << char('A' + x);
		if (i % 50 == 49)cout << endl;
	}
}