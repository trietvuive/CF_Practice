#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {
	int T = 1;
	int N = 6;
	srand(atoi(argv[1]));

	cout << T << endl;
	cout << N << endl;
	for (int i = 0; i < N; ++i) {
		cout << rand() % 10 + 1 << ' ';
	}
}
