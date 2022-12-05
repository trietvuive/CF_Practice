#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll n, chess[2005][2005];
ll l[5010], r[5010], base = 2500;

int main() {
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			cin >> chess[i][j];

	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			l[i+j] += chess[i][j],
			r[i-j+base] += chess[i][j];

	ll s1 = -1, s2 = -1;
	ll x1,y1,x2,y2;

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			ll s = l[i + j] + r[i - j + base] - chess[i][j];
			if((i + j) & 1) {
				if(s > s1)
					s1 = s, x1 = i+1, y1 = j+1;
			}
			else if(s > s2)
				s2 = s, x2 = i+1, y2 = j+1;
		}
	}
	cout << s1 + s2 << endl;
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

	
}
