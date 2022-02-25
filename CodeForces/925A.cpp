#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 2;
int s[MAX_N], e[MAX_N];

int time(int* a, int N, int h, int start, int end, int v)
{
	if (h == 0)return abs(start - end);

	int right_idx = lower_bound(a, a + N, start) - a, left_idx = right_idx - 1;
	int ans = 1 << 30;
	if (right_idx != N)
		ans = min(ans, abs(a[right_idx] - start) + abs(a[right_idx] - end));
	if (left_idx != -1)
		ans = min(ans, abs(a[left_idx] - start) + abs(a[left_idx] - end));
	return ans + (h % v ? h / v + 1 : h / v);


}


int main() {
	int n, m, ns, ne, v;
	cin >> n >> m >> ns >> ne >> v;
	for (int i = 0; i < ns; ++i)
		cin >> s[i];
	for (int i = 0; i < ne; ++i)
		cin >> e[i];
	
	int q; cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int stime = time(s, ns, abs(x1 - x2), y1, y2, 1);
		int etime = time(e, ne, abs(x1 - x2), y1, y2, v);
		cout << min(stime, etime) << endl;
	}
}