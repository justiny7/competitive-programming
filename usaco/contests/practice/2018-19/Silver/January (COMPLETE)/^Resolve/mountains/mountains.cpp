//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, ans=1;
pii a[mxN];

bool cmp(pii x, pii y) {
    if (x.fi^y.fi)
        return x.fi<y.fi;
    return x.se>y.se;
}

int main() {
    ifstream cin("mountains.in");
    ofstream cout("mountains.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        a[i]=pii(x-y, x+y);
    }
    sort(a, a+n, cmp);
    int cur=0;
    for (int i=1; i<n; ++i)
        if (a[i].se>a[cur].se)
            ++ans, cur=i;
    cout << ans << '\n';
}

