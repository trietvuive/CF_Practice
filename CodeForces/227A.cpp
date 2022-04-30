#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	ll product = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);
	if (product == 0)
		cout << "TOWARDS\n";
	else if (product > 0)
		cout << "LEFT\n";
	else cout << "RIGHT\n";
}