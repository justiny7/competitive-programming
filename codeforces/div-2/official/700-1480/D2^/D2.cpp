#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, ans, a[mxN], nxt[mxN], lst[mxN];

int main() {
    memset(lst, 0x3f, sizeof(lst));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=n-1; ~i; --i) {
        nxt[i]=lst[a[i]];
        lst[a[i]]=i;
    }
    int x=-1, y=-1;
    for (int i=0; i<n; ++i) {
        bool f=0;
        if (~x && a[x]==a[i])
            x=i, f=1;
        else if (~y && a[y]==a[i])
            y=i, f=1;
        if (f)
            continue;
        ++ans;
        if (x<0)
            x=i;
        else if (y<0)
            y=i;
        else if (nxt[x]>nxt[y])
            x=i;
        else
            y=i;
    }
    cout << ans << '\n';
}

