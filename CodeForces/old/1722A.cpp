#include<bits/stdc++.h>

using namespace std;

bool anagram(const string& a, const string& b) {
	vector<int> m(258, 0);
	for(char c : a) ++m[c];
	for(char c : b) if(--m[c] < 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);

	int tc, n; 
	cin >> tc;
	while(tc--) {
		string s;
		cin >> n >> s;
		if(n != 5 || !anagram(s, "Timur")) cout << "NO\n";
		else cout << "YES\n";
	}
}
