#include<bits/stdc++.h>

using ld = long double;
using namespace std;


template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }

    friend T distance(P a, P b) {
        a = a - b;
        return a.dist();
    }
};

template<class P>
vector<P> circleLine(P c, double r, P a, P b) {
	P ab = b - a, p = a + ab * (c-a).dot(ab) / ab.dist2();
	double s = a.cross(b, c), h2 = r*r - s*s / ab.dist2();
	if (h2 < 0) return {};
	if (h2 == 0) return {p};
	P h = ab.unit() * sqrt(h2);
	return {p - h, p + h};
}

template<class P> 
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
    auto d = (e1-s1).cross(e2-s2);
    if(d == 0) 
        return {-(s1.cross(e1,s2) == 0), P(0,0)};
    auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
    
    return {1, (s1 * p + e1 * q) / d};
}

using P = Point<ld>;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist() * (C-B).dist() * (A-C).dist()/
        abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

// Ox = a Ax + b Bx + c Cx / P
// Oy = a Ay + b By + c Cy / P
P inCenter(const P& A, const P& B, const P& C) {
    ld AB = distance(A,B), BC = distance(B,C), CA = distance(C,A);
    ld perimeter = AB + BC + CA;
    ld x = (BC * A.x + CA * B.x + AB * C.x)/perimeter, y = (BC * A.y + CA * B.y + AB * C.y)/perimeter;
    return P(x,y);
}

P findOpposite(const P& center, ld radius, const P& I, const P& A) {
    auto v = circleLine(center, radius, I, A);
    if(distance(v[0], A) < 1e-6) return v[1];
    return v[0];
}

vector<P> findPMN(const P& c, ld r, const P& I, const P& A, const P& B, const P& C) {
    return {findOpposite(c,r,I,C), findOpposite(c,r,I,A), findOpposite(c,r,I,B)};
}

void solve() {
    int label; 
    ld bx, cx, cy;
    cin >> label >> bx >> cx >> cy;

    P A(0,0), B(bx, 0), C(cx, cy);
    P I = inCenter(A,B,C);

    ld cc_radius = ccRadius(A, B, C);
    P cc_center = ccCenter(A, B, C);
    auto PMN = findPMN(cc_center, cc_radius, I, A, B, C);
    P E,F,G,H,J,K;
    E = lineInter(A, B, PMN[0], PMN[2]).second;
    F = lineInter(A, C, PMN[0], PMN[2]).second;
    G = lineInter(A, C, PMN[2], PMN[1]).second;
    H = lineInter(B, C, PMN[2], PMN[1]).second;
    J = lineInter(B, C, PMN[1], PMN[0]).second;
    K = lineInter(B, A, PMN[0], PMN[1]).second;

    
    cout << label << ' ';
    cout << fixed << setprecision(4);
    cout << distance(E,F) << ' ';
    cout << distance(F,G) << ' ';
    cout << distance(G,H) << ' ';
    cout << distance(H,J) << ' ';
    cout << distance(J,K) << ' ';
    cout << distance(K,E) << endl;
}

int main() {
    int tc; cin >> tc;
    while(tc--) solve();
}
