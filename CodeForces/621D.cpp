#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

string s[] = {"", "x^y^z", "x^z^y", "(x^y)^z", "y^x^z", "y^z^x", "(y^x)^z", "z^x^y", "z^y^x", "(z^x)^y"};
long double x,y,z;

void solve() {
	cin >> x >> y >> z;
	long double a[] = {0, log(x) * pow(y, z), log(x) * pow(z, y), log(x) * y * z, log(y) * pow(x, z), 
						log(y) * pow(z, x), log(y) * x * z, log(z) * pow(x, y), 
						log(z) * pow(y, x), log(z) * x * y};

	int t = 1;
	for(int i = 2; i < 10; ++i) {
		if(a[i] > a[t]) t = i;
	}
	cout << s[t] << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

