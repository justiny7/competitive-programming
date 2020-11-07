#include <bits/stdc++.h>
using namespace std;

struct ring {
    int x, y, r, R;
} a, b;

inline int sq(int x) {
    return x*x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> a.x >> a.y >> a.r >> a.R;
    cin >> b.x >> b.y >> b.r >> b.R;
    int cdist=sq(a.x-b.x)+sq(a.y-b.y), cnt=0;
    if (cdist<=sq(a.r-b.r))
        ++cnt;
    if (cdist<=sq(a.R-b.R))
        ++cnt;
    if ((cdist<=sq(a.r-b.R) && cdist<=sq(a.r-b.r) && a.r>b.R) ||
        (cdist<=sq(b.r-a.R) && cdist<=sq(a.r-b.r) && b.r>a.R))
        cnt+=2;
    if (cdist>=sq(a.r+b.R))
        ++cnt;
    if (cdist>=sq(a.R+b.r))
        ++cnt;
    if (cdist>=sq(a.R+b.R))
        cnt+=2;
    cout << cnt << '\n';
}


