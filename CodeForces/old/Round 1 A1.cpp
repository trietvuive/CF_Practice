#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int MAX_N = 52;
int matrix[MAX_N][MAX_N];

int main() {
	ofstream out_file;
	ifstream in_file;
	out_file.open("text/output.txt");
	in_file.open("text/input.txt");
	int tc;
	in_file >> tc;
	for (int case_n = 1; case_n <= tc; ++case_n)
	{
		out_file << "Case #" << case_n << ": ";
		int n, ans = 0;
		in_file >> n;
		string s;
		in_file >> s;
		char c = '#';
		for (int i = 0; i < n; ++i)
		{
			if (s[i] == c || s[i] == 'F')continue;
			else ++ans, c = s[i];
		}
		out_file << max(0,ans-1) << endl;
	}
	out_file.close();
}
