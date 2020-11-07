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
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

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

template<class T> bool ckmin(T& a, const T& b) {return (b<a)?a=b, 1:0;}
template<class T> bool ckmax(T& a, const T& b) {return (a<b)?a=b, 1:0;}

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

void fileIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int mxN=3e5+1;
int n, m, source;
vll adj[mxN];
ll dist[mxN], par[mxN];
map<pll, int> which;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n >> m;
    ff0r(i, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
        which[mp(a, b)]=which[mp(b, a)]=i+1;
    }
    cin >> source;
    memset(dist, 0x7f, sizeof(dist));
    memset(par, -1, sizeof(par));
    dist[source]=0;
    par[source]=-1;
    pqueue<pll, vll, greater<pll>> pq;
    pq.push({0, source});
    while (!pq.empty()) {
        ll d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (d_v!=dist[v])
            continue;
        in(p, adj[v]) {
            ll u=p.fi, d=p.se;
            if (dist[v]+d<dist[u]) {
                dist[u]=dist[v]+d;
                par[u]=v;
                pq.push({dist[u], u});
            }
            else if (dist[v]+d==dist[u])
                if (dist[u]-dist[par[u]]>d)
                    par[u]=v;
        }
    }
    vll ans;
    ll sum=0;
    ffor(i, 1, n+1)
        if (i!=source) {
            ans.pb(mp(i, par[i]));
            sum+=dist[i]-dist[par[i]];
        }
    cout << sum << '\n';
    in(p, ans)
        cout << which[p] << " ";
    cout << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


