#include<iostream>

using namespace std;

int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int n, a, b, black_small_edge;
		cin >> n >> a >> b;
		black_small_edge = n - max(a, b);
		int white, black;
		cin >> white >> black;
		white -= min(a, b);
		white -= abs(a - b) / 2;
		black -= black_small_edge;
		black -= abs(a - b) / 2;
		if (black <= 0 && white <= 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
