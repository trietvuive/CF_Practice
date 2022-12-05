#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, h; cin >> n >> h;
    vector<int> bottom, top;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if(x % 2) top.push_back(h-x);
        else bottom.push_back(x);
    }

    int min_hit = n, min_cnt = 0;
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int top_idx = 0, bottom_idx = 0;
    for(int i = 1; i <= h; ++i) {
        // hit any bottom that's >= h
        // and any top that's < h
       while(bottom_idx < bottom.size() && bottom[bottom_idx] < i) {
           ++bottom_idx;
       }

       while(top_idx < top.size() && top[top_idx] < i) {
           ++top_idx;
       }

       cout << i << ' ' << bottom_idx << ' ' << top_idx << endl;
       int hit = top_idx + n/2 - bottom_idx;
       cout << i << " " << hit << endl << endl;
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    solve();
}
