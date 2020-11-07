#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, a[mxN], c1, c2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        if (a[i])
            ++c1;
        else
            ++c2;
    }
    for (int i=0, k1=0, k2=0; i<n; ++i) {
        if (a[i])
            ++k1;
        else
            ++k2;
        if (k1==c1 || k2==c2) {
            cout << i+1 << '\n';
            break;
        }
    }
}

