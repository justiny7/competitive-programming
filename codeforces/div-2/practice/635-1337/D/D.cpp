#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define rsz resize
#define ins insert
#define mp make_pair
#define beg(x) x.begin()
#define en(x) x.end()
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound

#define ffor(i, a, b) for (int (i)=a; i<b; ++i)
#define rfor(i, a, b) for (int (i)=b-1; i>=a; --i)
#define ff0r(i, a) for (int (i)=0; i<a; ++i)
#define rf0r(i, a) for (int (i)=a-1; i>=0; --i)
#define in(i, x) for (auto& i : x)
#define fitfor(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define ritfor(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

using ll=long long;
using db=double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using pdd=pair<db, db>;
using vi=vector<int>;
using vl=vector<ll>;
using vd=vector<db>;
using vs=vector<string>;
using vii=vector<pii>;
using vll=vector<pll>;
using vdd=vector<pdd>;

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

ll sq(ll a) {
    return a*a;
}

ll cmp(ll a, ll b, ll c) {
    return (sq(a-b)+sq(a-c)+sq(b-c));
}

ll solve(vl a, vl b, vl c) {
    ll cans=LLONG_MAX;
    in(i, a) {
        auto hi=ub(all(b), i), lo=lb(all(c), i);
        if (hi==beg(b) || lo==en(c))
            continue;
        --hi;
        cans=min(cans, cmp(i, *hi, *lo));
    }
    return cans;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int nr, ng, nb;
        ll ans=LLONG_MAX;
        cin >> nr >> ng >> nb;
        vl r(nr), g(ng), b(nb), rg(nr), rb(nr), gb(ng);
        ff0r(i, nr) cin >> r[i];
        ff0r(i, ng) cin >> g[i];
        ff0r(i, nb) cin >> b[i];
        sort(all(r)); sort(all(g)); sort(all(b));
        ans=min({ans, solve(r, g, b), solve(r, b, g), solve(b, r, g)});
        ans=min({ans, solve(g, r, b), solve(g, b, r), solve(b, g, r)});
        cout << ans << '\n';
    }
    cerr << "\nTime elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

