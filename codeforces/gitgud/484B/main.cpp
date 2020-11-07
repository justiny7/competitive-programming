#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, a[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
}

