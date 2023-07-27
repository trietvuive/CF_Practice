#include<bits/stdc++.h>
#include <math.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;

template <class T> int sgn(T x) {
	return (x > 0) - (x < 0);
}

template<class T>
struct Point {
	using P = Point;
	T x,y;
	explicit Point(T x = 0, T y = 0): x(x), y(y) {}
	friend ostream& operator << (ostream& os, const Point& p) {
		os << p.x << ' ' << p.y;
		return os;
	}

	bool operator< (P p) const {
		return tie(x,y) < tie(p.x,p.y); 
	}
	bool operator== (P p) const {
		return tie(x,y) == tie(p.x, p.y);
	}
	P operator+ (P p) const {
		return P(x+p.x, y+p.y);
	}
	P operator- (P p) const {
		return P(x-p.x, y-p.y);
	}
	P operator * (T d) const {
		return P(x*d, y*d);
	}
	T dot(P p) const {
		return x*p.x + y*p.y;
	}
	T cross(P p) const {
		return x*p.y - y*p.x;
	}
	T cross(P a, P b) const {
		return (a-*this).cross(b-*this);
	}
	T dist2() const {
		return x*x + y*y;
	}
	P operator/(T d) const {
		return P(x/d, y/d);
	}
};

using P = Point<double>;
#define arg(p, q) atan2(p.cross(q), p.dot(q))

double circlePoly(P c, double r, vector<P>& ps) {
	auto tri = [&](P p, P q) {
		auto r2 = r*r/2;
		P d = q-p;
		auto a = d.dot(p)/d.dist2(), b = (p.dist2()-r*r)/d.dist2();
		auto det = a*a-b;
		if(det <= 0) return arg(p,q) * r2;
		auto s = max(0., -a-sqrt(det)), t = min(1., -a+sqrt(det));
		if(t < 0 || 1 <= s) return arg(p,q) * r2;
		P u = p + d * s, v = p + d * t;
		return arg(p,u) * r2 + u.cross(v)/2 + arg(v,q) * r2;
	};
	auto sum = 0.;
	for(int i = 0; i < ps.size(); ++i)
		sum += tri(ps[i] - c, ps[(i+1) % ps.size()] - c);
	return sum;
}

template<class T>
T polygonArea(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	for(int i = 0; i+1 < v.size(); ++i) 
		a += v[i].cross(v[i+1]);
	return a/2;
}

P polygonCenter(const vector<P>& v) {
	P res(0,0); double A =  0;
	for(int i = 0, j = v.size() - 1; i < v.size(); j = i++) {
		res = res + (v[i] + v[j]) * v[j].cross(v[i]);
		A += v[j].cross(v[i]);
	}
	return res / A / 3;
}

void solve() {
	int n; cin >> n;
	vector<P> points;
	for(int i = 0; i < n; ++i) {
		double x, y; cin >> x >> y;
		points.push_back(P(x,y));
	}

	double area = polygonArea(points);
	P center = polygonCenter(points);
	double radius = sqrt(area/M_PI);

	cout << setprecision(4) << fixed << circlePoly(center, radius, points)/area << endl;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int tc = 1;
	while(tc--) solve();
}

