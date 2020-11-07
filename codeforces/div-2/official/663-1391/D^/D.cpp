#include <bits/stdc++.h>
using namespace std;
using vs=vector<string>;

int n, m;
vs a;

int solve() {
    if (n==1)
        return 0;
    if (n>3)
        return -1;
    if (n==2) {
        int cnt[2];
        fill(cnt, cnt+2, m);
        for (int i=0; i<m; ++i)
            --cnt[(i&1)^(a[0][i]^a[1][i])];
        return min(cnt[0], cnt[1]);
    }
    int cnt[4];
    fill(cnt, cnt+4, m);
    for (int i=0; i<m; ++i) {
        int x=(i&1)^(a[0][i]^a[1][i]),
            y=(i&1)^(a[1][i]^a[2][i]);
        --cnt[x*2+y];
    }
    return *min_element(cnt, cnt+4);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    a=vs(n);
    for (int i=0; i<n; ++i)
        cin >> a[i];
    cout << solve() << '\n';
}


