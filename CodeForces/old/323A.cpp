#include<bits/stdc++.h>
using namespace std; 
int k; 
int main() { 
	cin >> k; 
	if (k & 1)
		return puts("-1"), 0; 
	int i, j, r; 
	for (i = 0; i < k; puts(""), i++)
		for (j = 0; j < k; puts(""), j++)
			for (r = 0; r < k; r++)
				printf((j / 2 % 2) ^ (r / 2 % 2) ^ (i % 2) ? "w" : "b"); 
}