#include <bits/stdc++.h>
using namespace std;

const int mxN=5e3+1;
int n, a[mxN];

int go(int l=0, int r=n-1) {
    if (r<l)
        return 0;
    if (r-l+1<2)
        return (a[l]?r-l+1:0);
    int mn=INT_MAX;
    for (int i=l; i<=r; ++i)
        mn=min(mn, a[i]);
    int cur=mn, lst=l;
    for (int i=l; i<=r; ++i) {
        a[i]-=mn;
        if (!a[i])
            cur+=go(lst, i-1), lst=i+1;
    }
    cur+=go(lst, r);
    return min(cur, r-l+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    cout << go() << '\n';
}

