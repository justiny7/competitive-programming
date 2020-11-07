#include <bits/stdc++.h>
using namespace std;

const int mxV=1e6+1;
int n, d[mxV];

int main() {
    for (int i=1; i<mxV; ++i)
        for (int j=i; j<mxV; j+=i)
            ++d[j];
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--) {
        int a; cin >> a;
        cout << d[a] << '\n';
    }
}

