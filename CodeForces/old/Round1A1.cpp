#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int a[500005], b[500005], n, k;
bool rotated() {
	for(int i = 0; i < n; ++i) {
		int ai = i, bi = 0;
		while(bi < n && a[ai % n] == b[bi % n])
			++ai, ++bi;
		if(bi == n) return true;
	}
	return false;
}

bool equal() {
	for(int i = 0; i < n; ++i) if(a[i] != b[i]) return false;
	return true;
}
bool solve() {
	if(k == 0) return equal();
	return rotated();
}
int main() {
	auto start = high_resolution_clock::now();
	freopen("in/sample.txt", "r", stdin);
	freopen("out/sample.txt", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int tc; cin >> tc;
	for(int i = 1; i <= tc; ++i) {
		cin >> n >> k;
		for(int i = 0; i < n; ++i) cin >> a[i];
		for(int i = 0; i < n; ++i) cin >> b[i];
		cout << "Case #" << i;
		if(solve())
			cout << ": YES\n";
		else
			cout << ": NO\n";
	}
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cerr << "Duration count: " << duration.count() << endl;
}
