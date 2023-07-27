#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using graph = vector<vector<int>>;
constexpr int N = 5e5 + 5;
int f[N],n,T;
stack<pair<int,int>> st;

void update(int i,int v){
	for(;i<N;i+=i&-i)
		f[i]=max(f[i],v);
}

int query(int i){
	int res=0;
	for (;i;i-=i&-i) 
		res=max(res,f[i]);
	return res;
}

void solve() {
	st = stack<pair<int,int>>();
	memset(f,0,sizeof f);
	cin >> n;

	st.push(make_pair(1,1));
	update(1,1);

	for(int i=0;i<n;++i){
		int a; cin>>a;
		int t = query(a)+1;
		while(!st.empty()&&st.top().first<=a){
			update(st.top().first,st.top().second+1);
			st.pop();
		}
		st.push(make_pair(a,t));
		update(a,t);
	}
	cout << query(N-1) - 1 << '\n';

}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> T;
	while(T--)
		solve();
}
