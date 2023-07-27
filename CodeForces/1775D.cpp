#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

vector<int> depth[300005];
int a[300005], smallest_factor[300005], n, s, t;

int gcd(int a, int b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

void prime_sieve() {
	for (int i = 2; i <= 300000; i++) {
		if (smallest_factor[i] == 0) {
			smallest_factor[i] = i;
			for (int j = i + i; j <= 300000; j += i) {
				if (smallest_factor[j] == 0) {
					smallest_factor[j] = i;
				}
			}
		}
	}
}

void add_prime(int x, set<int> &s) {
	while (x > 1) {
		int p = smallest_factor[x];
		s.insert(p);
		while (x % p == 0) {
			x /= p;
		}
	}
}

bool divisible(int x, set<int> &s) {
	while (x > 1) {
		int p = smallest_factor[x];
		if (s.find(p) != s.end()) {
			return true;
		}
		while (x % p == 0) {
			x /= p;
		}
	}
	return false;
}

int bfs() {
	set<int> primes, visited;
	depth[0].push_back(s);
	visited.insert(s);

	add_prime(a[s], primes);
	int d = 1;
	while(!primes.empty()) {
		set<int> s;
		for(int i = 1; i <= n; ++i) {
			if(visited.count(i)) continue;
			if(divisible(a[i], primes)) {
				if(i == t) return d;
				depth[d].push_back(i);
				visited.insert(i);
				add_prime(a[i], s);
			}
		}
		primes = s;
		++d;
	}

	return -1;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	cin >> s >> t;
	if(s == t) {
		cout << 1 << endl << s << endl;
		return;
	}

	prime_sieve();
	int d = bfs();

	if(d == -1) {
		cout << -1 << endl;
		return;
	}

	vector<int> paths;
	paths.push_back(t);
	for(int i = d-1; i >= 0; --i) {
		for(int j : depth[i]) {
			if(gcd(a[j], a[t]) > 1) {
				paths.push_back(j);
				t = j;
				break;
			}
		}
	}

	reverse(paths.begin(), paths.end());
	cout << paths.size() << endl;
	for(int i : paths) {
		cout << i << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

