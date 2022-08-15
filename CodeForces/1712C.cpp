#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;
int a[100002];
int main() {
	int tc; cin >> tc;
	while(tc--) {
		int n; cin >> n;
		for(int i = 1; i <= n; ++i) cin >> a[i];
		int idx = n, curtain = -1;
		while(idx > 1 && a[idx] >= a[idx-1]) --idx;
		--idx;

		unordered_set<int> s;
		for(int i = 1; i <= idx; ++i) s.insert(a[i]);
		for(int i = idx; i <= n; ++i)
			if(s.find(a[i]) != s.end()) curtain = i;
		for(int i = idx; i <= curtain; ++i) s.insert(a[i]);
		//cout << "DEBUG: " << idx << ' ' << curtain << endl;
		cout << s.size() << endl;
	}
}
