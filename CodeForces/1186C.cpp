#include<bits/stdc++.h>
using namespace std;
string a, b;
int s, k = 1, i;

int main() {
    cin >> a >> b;
    for (; b[i]; i++)
        k ^= a[i] ^ b[i];

    //when compare new substring, it's as if the old substring shift left by 1, remove leftmost and add a rightmost element
    // we can compare old substring and new substring. if their mismatch is even, a/b mismatch doesn't change sign
    for (s = k; a[i]; i++)
        s += k ^= a[i] ^ a[i - b.size()];
    printf("%d\n", s);

    return 0;
}
