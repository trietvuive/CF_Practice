#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<ll>>;
constexpr ll MOD = 1e9 + 7;

graph stations, lines;
ll n,m,a,INF, MUL = 1e4;
vector<ll> options;
map<ll, ll> ans;


void preprocess() {
	cin >> m >> n;
	cin >> a;
	INF = 1e6 * a;

	stations.resize(n+1);
	lines.resize(m+1);

	for(int line = 1; line <= n; ++line) {
		int sz; cin >> sz;
		for(int j = 0, station; j < sz; ++j) {
			cin >> station; 
			lines[station].push_back(line);
			stations[line].push_back(station);
		}
	}

	set<pair<int,int>> st;
	priority_queue<tuple<int,int,int>> pq;
	for(int line : lines[1]) 
		pq.emplace(0, 1, line);

	while(!pq.empty()) {
		auto [cost, station, line] = pq.top(); pq.pop();
		st.insert({station, line});

		if(station == m) {
			options.push_back(cost);
			continue;
		}

		for(int next_line : lines[station]) {
			if(st.count({station, next_line})) continue;
			pq.emplace(cost + INF, station, next_line);
		}

		for(int next_station : stations[line]) {
			if(st.count({next_station, line})) continue;
			pq.emplace(cost + a, next_station, line);
		}
	}

	sort(options.begin(), options.end());
	for(int option : options) cout << option << ' ';
	cout << endl;
	for(int i = options.size() - 1; i >= 0; --i) {
		ans[options[i] / INF] = options[i] % INF;
	}
}

void solve() {
	ll b, mn = LLONG_MAX;
	cin >> b;
	for(auto& [bc, ac] : ans) 
		mn = min(mn, bc * b + ac);
	cout << mn << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	preprocess();
	cout << "HELLO\n";
	int tc;
	cin >> tc;
	while(tc--) solve();
}

