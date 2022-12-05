#include<bits/stdc++.h>
#define gpii vector<vector<pair<int,int>>>
using namespace std;

inline bool get_bit(int x, int bit) { return (x >> bit) & 1; }
inline void make_one(int& x, int bit) { x |= (1 << bit); }
inline void make_zero(int& x, int bit) { x &= ~(1 << bit); }

void solve_graph(int bt, gpii& graph, vector<int>& ans) {
    for(int i = 0; i < ans.size(); ++i)
        for(auto& it : graph[i]) 
            if(!get_bit(it.second, bt))
                make_zero(ans[i], bt);
    
    for(int i = 0; i < ans.size(); ++i) {
        if(get_bit(ans[i], bt)) {
            make_zero(ans[i], bt);
            for(auto& it : graph[i])
                if(!get_bit(ans[it.first], bt) && get_bit(it.second, bt)) {
                    make_one(ans[i], bt);
                    break;
                }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int j,k,x,n,q;
    cin >> n >> q;

    vector<int> ans(n, ~(1 << 31));
    gpii graph(n);

    for(int i = 0; i < q; ++i) {
        cin >> j >> k >> x;
        --j; --k;
        graph[j].push_back({k,x});
        graph[k].push_back({j,x});
    }

    for(int bt = 0; bt < 31; ++bt) solve_graph(bt, graph, ans);

    for(int i = 0; i < n; ++i) 
        cout << ans[i] << ' ';

    cout << '\n';
}
