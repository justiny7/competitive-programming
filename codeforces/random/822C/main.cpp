#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n, x, ans=LLONG_MAX, best[mxN];
struct voucher {
    ll l, r, c, len;
};
struct event {
    voucher v;
    int t, f;
    bool operator<(const event& e) const {
        if (t^e.t)
            return t<e.t;
        return f>e.f;
    }
} a[mxN*2];


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> x;
    for (int i=0; i<n; ++i) {
        int ll, rr, cc;
        cin >> ll >> rr >> cc;
        voucher v{ll, rr, cc, rr-ll+1};
        event e{v, ll, 1},
              e2{v, rr, 0};
        a[i*2]=e, a[i*2+1]=e2;
    }
    sort(a, a+n*2);
    memset(best, 0x7f, sizeof(best));
    for (int i=0; i<n*2; ++i) {
        if (a[i].f) {
            ll t=x-a[i].v.len;
            if (t>0 && best[t]<INF)
                ans=min(ans, a[i].v.c+best[t]);
        }
        else
            best[a[i].v.len]=min(best[a[i].v.len], a[i].v.c);
    }
    cout << (ans<LLONG_MAX?ans:-1) << '\n';
}


