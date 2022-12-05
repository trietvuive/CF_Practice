#include <bits/stdc++.h>
#define N 2002
using namespace std;
deque<tuple<int, int, int, int>> Q;
int n, m, r, c, x, y, i, j, z;
bool L[N][N], V[N][N];
string s;
int main() {
    cin >> n >> m >> r >> c >> x >> y;
    for (i = 1; i <= n; ++i) {
        cin >> s, j = 1;
        for (char c : s)L[i][j++] = '.' == c;
    }
    Q.push_front({ r,c,x,y });
    while (!Q.empty()) {
        auto [a, b, X, Y] = Q.front(); Q.pop_front();
        if (!L[a][b] || V[a][b] || X < 0 || Y < 0) continue;
        V[a][b] = 1, z++;
        Q.push_front({ a + 1,b,X,Y });
        Q.push_front({ a - 1,b,X,Y });
        Q.push_back({ a,b + 1,X,Y - 1 });
        Q.push_back({ a,b - 1,X - 1,Y });
    }
    cout << z;
}