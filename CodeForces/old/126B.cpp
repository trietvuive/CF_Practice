#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;


int main() {
    string s; cin >> s;
    int n = s.size(), l = -1, r = -1, mx = 0;
    vector<int> z(n, 0);
    for(int i = 1; i < n; ++i) {
        if(i <= r) z[i] = min(z[i-l], r-i+1);
        while(i + z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if(i + z[i] - 1 > r) r = i + z[i] - 1, l = i;
    }

    set<int> suffix;
    for(int i = n-1; i > 0; --i) {
        if(suffix.size() > 0) {
			auto iter = suffix.upper_bound(z[i]);
			if(iter != suffix.begin()) {
				--iter;
				mx = max(mx, min(z[i], *iter));
			}
		}
        if(i + z[i] == n) 
            suffix.insert(z[i]);
    }

    if(mx == 0)
        cout << "Just a legend" << endl;
    else
        cout << s.substr(0, mx) << endl;
}
