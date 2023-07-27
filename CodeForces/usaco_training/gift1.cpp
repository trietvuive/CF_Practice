/*
ID: triet_v1
LANG: C++
TASK: gift1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	map<string, int> names;
	vector<string> name_list(n);
	vector<int> money(n);

	for(int i = 0; i < n; ++i) {
		string name; cin >> name;
		names[name] = i;
		name_list[i] = name;
	}

	for(int i = 0; i < n; ++i) {
		string name; cin >> name;
		int m, p; cin >> m >> p;
		if(p == 0) continue;
		money[names[name]] -= m - m % p;
		for(int j = 0; j < p; ++j) {
			string name; cin >> name;
			money[names[name]] += m / p;
		}
	}
	for(int i = 0; i < n; ++i) {
		cout << name_list[i] << " " << money[i] << endl;
	}
}

int main() {
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	int tc = 1;
	while(tc--) solve();
}

