#include<bits/stdc++.h>
#define double long double
const double PI = 3.14159265358979323;
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

double circle_arc(double r, double len) {
	return 2*asin(len/2/r);
}

bool is_polygon(const vector<double>& len) {
	double mx = *max_element(len.begin(), len.end());
	double sm = accumulate(len.begin(), len.end(), 0.);
	return sm <= 2*mx;
}

vector<double> get_arcs(double radius, const vector<double>& lens) {
	vector<double> arcs;
	for(auto len : lens)
		arcs.push_back(circle_arc(radius, len));
	return arcs;
}

bool equal(double a, double b) {
	return abs(a-b) <= 1e-8;
}

bool is_interior_too_large(double radius, const vector<double>& len) {
	auto arcs = get_arcs(radius, len);
	double arc_sum = accumulate(arcs.begin(), arcs.end(), 0.);
	return arc_sum < 2*PI + 1e-8;
}

bool is_interior(double radius, const vector<double> &len) {
	return *max_element(len.begin(), len.end()) < 2*radius - 1e-8;
}

double binary_search_interior(const vector<double>& len) {
	double lo = 0., hi = 1e8;
	while(hi - lo >= 1e-8) {
		double mid = (lo + hi) / 2;
		if(is_interior_too_large(mid, len))
			hi = mid;
		else lo = mid;
	}
	return lo;
}

void solve() {
	vector<double> lengths;
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		double x; cin >> x;
		lengths.push_back(x);
	}

	if(is_polygon(lengths)) {
		cout << "NO CIRCLE\n";
		return;
	}

	double interior_ans = binary_search_interior(lengths);
	bool valid = is_interior(interior_ans, lengths);

	if(!valid) cout << "OUTSIDE\n";
	else if(interior_ans > 120.) cout << "TOO BIG\n";
	else cout << setprecision(4) << fixed << interior_ans << '\n';
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

