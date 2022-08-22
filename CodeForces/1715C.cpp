#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[100002], b[100002], n, m;
ll sm;

void change(int idx) {
    int old_val = b[idx];
    b[idx] = a[idx] != a[idx-1];

    if(old_val != b[idx]) {
        if(b[idx] == 1) sm += (idx-1) * (n-idx+1);
        else sm -= (idx-1) * (n-idx+1);
    }
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i], b[i] = (a[i] != a[i-1]);

	for(int i = 1; i <= n; ++i) 
        sm += b[i] * (i-1) * (n-i+1) + (n-i+1);

    for(int q = 1; q <= m; ++q) {
        int i,x; cin >> i >> x;
        a[i] = x;
        change(i);
        change(i + 1);
        cout << sm << '\n';
    }
}
