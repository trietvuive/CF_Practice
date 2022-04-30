#include <iostream>
using namespace std;

int main() {
    int tc; cin >> tc;
    for (int i = 1; i <= tc; ++i) {
        printf("Case #%d:\n", i);
        int r, c; cin >> r >> c;
        for (int i = 0; i < r; ++i) {
            if (i == 0) cout << "..+";
            else cout << "+-+";
            for (int j = 1; j < c; ++j) cout << "-+";
            cout << endl;

            if (i == 0) cout << "..|";
            else cout << "|.|";
            for (int j = 1; j < c; ++j) cout << ".|";
            cout << endl;
        }
        cout << "+-+";
        for (int j = 1; j < c; ++j) cout << "-+";
        cout << endl;

    }
}