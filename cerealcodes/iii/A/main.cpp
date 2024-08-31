#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n * n; i++) {
        if (i > 0 && i % n == 0) {
            cout << '\n';
        }
        cout << (i < k);
    }
}
