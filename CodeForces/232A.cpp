#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int K, a[N][N], e, s;

//induction: given a complete graph
// if you add a node and 2 edges on that node, you'll get 1 more 3-cycle
// 3 edges = 2 extra 3-cycles (3rd edge - 1st edge - node and 3rd edge - 2nd edge - node. rmb complete graph so all nodes connected)
// = 3 more 3-cycles
// 4 edges = 3 extra 3-cycles = 6 more 3-cycles
// then, n edges = n*(n-1)/2 more 3-cycles

int main()
{
	cin >> K;
	while (K)
	{
		for (e = 0; e <= s && e * (e - 1) / 2 <= K; ++e);
		--e;
		K -= e * (e - 1) / 2;
		for (int i = 0; i < e; ++i)a[i][s] = a[s][i] = 1;
		++s;
	}
	cout << s << endl;
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) cout << a[i][j];
		cout << endl;
	}
}