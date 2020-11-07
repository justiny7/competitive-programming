#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll n, m, ns, ne, v, q;
set<ll> s, e;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> ns >> ne >> v;
    for (int i=0; i<ns; ++i) {
        ll a; cin >> a;
        s.insert(a);
    }
    for (int i=0; i<ne; ++i) {
        ll a; cin >> a;
        e.insert(a);
    }
    cin >> q;
    while (q--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a==c) {
            cout << abs(d-b) << '\n';
            continue;
        }
        ll c1=LLONG_MAX, c2=LLONG_MAX;
        if (s.size()) {
            auto it=s.upper_bound(b);
            auto it2=it--;
            if (it2!=s.begin())
                c1=min(c1, abs(*it-d)+abs(*it-b));
            if (it2!=s.end())
                c1=min(c1, abs(*it2-d)+abs(*it2-b));
            auto it3=s.upper_bound(d);
            auto it4=it3--;
            if (it4!=s.begin())
                c1=min(c1, abs(*it3-d)+abs(*it3-b));
            if (it4!=s.end())
                c1=min(c1, abs(*it4-d)+abs(*it4-b));
            c1+=abs(a-c);
        }
        if (e.size()) {
            auto it=e.upper_bound(b);
            auto it2=it--;
            if (it2!=e.begin())
                c2=min(c2, abs(*it-d)+abs(*it-b));
            if (it2!=e.end())
                c2=min(c2, abs(*it2-d)+abs(*it2-b));
            auto it3=e.upper_bound(d);
            auto it4=it3--;
            if (it4!=e.begin())
                c2=min(c2, abs(*it3-d)+abs(*it3-b));
            if (it4!=e.end())
                c2=min(c2, abs(*it4-d)+abs(*it4-b));
            c2+=(abs(a-c)+v-1)/v;
        }
        cout << min(c1, c2) << '\n';
    }
}

