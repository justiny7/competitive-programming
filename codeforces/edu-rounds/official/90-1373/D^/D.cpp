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

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans=0, evensum=0;
        vl a(n), b(n);
        ff0r(i, n) {
            cin >> a[i];
            if (i&1)
                b[i]=a[i];
            else {
                evensum+=a[i];
                b[i]=-1*a[i];
            }
        }
        ll cmax=0, totmax=0;
        pii maxpos={0,0}, curpos={0,0};
        for (int i=1; i<n-1; i+=2) {
            ll cur=b[i]+b[i+1];
            if (cur+cmax>=0)
                cmax+=cur;
            else
                cmax=0;
            totmax=max(cmax, totmax);
        }
        cmax=0;
        for (int i=0; i<n-1; i+=2) {
            ll cur=b[i]+b[i+1];
            if (cur+cmax>=0)
                cmax+=cur;
            else
                cmax=0;
            totmax=max(cmax, totmax);
        }
        cout << evensum+totmax << '\n';
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

