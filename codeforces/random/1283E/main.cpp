#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+10;
int n, a[mxN];
bool have[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    sort(a, a+n);
    int mn=0, mx=0;
    for (int i=0; i<n; ++i) {
        int v=a[i];
        if (!have[v])
            ++mn, have[v]=have[v+1]=have[v+2]=1;
    }
    memset(have, 0, sizeof(have));
    for (int i=0; i<n; ++i) {
        int v=a[i];
        if (!have[v-1])
            have[v-1]=1, ++mx;
        else if (!have[v])
            have[v]=1, ++mx;
        else if (!have[v+1])
            have[v+1]=1, ++mx;
    }
    cout << mn << " " << mx << '\n';
}

