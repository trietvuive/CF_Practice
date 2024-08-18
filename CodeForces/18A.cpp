#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using graph = vector<vector<int>>;
constexpr ll MOD = 1e9 + 7;

struct Point {
  ll x, y;
  Point(int x, int y) : x(x), y(y) {}
  bool operator == (const Point &p) {
    return x == p.x && y == p.y;
  }
};

ll square_distance(Point p1, Point p2) {
  return (p1.x - p2.x) * (p1.x - p2.x) +
         (p1.y - p2.y) * (p1.y - p2.y);
}

bool is_right_angle(Point p1, Point p2, Point p3) {
  if (p1 == p2 || p2 == p3 || p1 == p3) return false;
  ll d1 = square_distance(p1, p2), d2 = square_distance(p1, p3), d3 = square_distance(p2, p3);
  return d1 + d2 == d3 || d1 + d3 == d2 || d2 + d3 == d1;
}

bool almost_right_angle(Point p1, Point p2, Point p3) {
  return is_right_angle(p1, p2, Point(p3.x, p3.y + 1)) ||
        is_right_angle(p1, p2, Point(p3.x, p3.y - 1)) ||
        is_right_angle(p1, p2, Point(p3.x + 1, p3.y)) ||
        is_right_angle(p1, p2, Point(p3.x - 1, p3.y));
}

void solve() {
  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  Point p1(x1, y1), p2(x2, y2), p3(x3, y3);
  if(is_right_angle(p1, p2, p3))
    cout << "RIGHT" << endl;
  else if(almost_right_angle(p1, p2, p3) ||
          almost_right_angle(p2, p3, p1) ||
          almost_right_angle(p3, p1, p2))
    cout << "ALMOST" << endl;
  else
    cout << "NEITHER" << endl;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(nullptr);
  int tc = 1;
  while(tc--) solve();
}

