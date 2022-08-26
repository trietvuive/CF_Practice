#include<bits/stdc++.h>

using namespace std;

char board[255][255];
bool visited[255][255];
long long noise[255][255], n,m,q,p;

void bfs(int row, int col, int curr_noise) {
    queue<int> q;
    vector<int> visited(n*m, false);
    q.push(row*m + col);
    int dividor = 1;
    while(!q.empty()) {
        int sz = q.size();
        for(int i = 0; i < sz; ++i) {
            int top = q.front(); q.pop();
            int r = top / m,  c = top % m;
            if(visited[r*m + c] || board[r][c] == '*') continue; 

            noise[r][c] += curr_noise / dividor;
            visited[r*m + c] = true;

            if(r-1 >= 0) q.push((r-1) * m + c);
            if(r+1 < n) q.push((r+1) * m + c);
            if(c-1 >= 0) q.push(r * m + c - 1);
            if(c+1 < m) q.push(r * m + c + 1);
        }
        dividor *= 2;
        if(dividor > curr_noise) break;
    }
}

void solve() {
    cin >> n >> m >> q >> p;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j) 
            cin >> board[i][j];

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) 
            if(board[i][j] >= 'A' && board[i][j] <= 'Z') 
                bfs(i, j, (board[i][j] - 'A' + 1) * q);

    int ans = 0;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            ans += noise[i][j] > p;
    
    cout << ans << endl;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    solve();
}
