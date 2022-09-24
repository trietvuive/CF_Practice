#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		string s;
		unordered_set<string> p1, p2, p3;
		for(int i = 0; i < n; ++i) cin >> s, p1.insert(s);
		for(int i = 0; i < n; ++i) cin >> s, p2.insert(s);
		for(int i = 0; i < n; ++i) cin >> s, p3.insert(s);

		int s1 = 0, s2 = 0, s3 = 0;
		for(const string& s : p1) {
			int found = (p2.find(s) != p2.end()) + (p3.find(s) != p3.end());
			s1 += found == 0 ? 3 : found == 1 ? 1 : 0;
		}

		for(const string& s : p2) {
			int found = (p1.find(s) != p1.end()) + (p3.find(s) != p3.end());
			s2 += found == 0 ? 3 : found == 1 ? 1 : 0;
		}

		for(const string& s : p3) {
			int found = (p1.find(s) != p1.end()) + (p2.find(s) != p2.end());
			s3 += found == 0 ? 3 : found == 1 ? 1 : 0;
		}

		cout << s1 << ' ' << s2 << ' ' << s3 << '\n';
	}
}
