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

const int mxN=2e5+1;
int n, m, t, in[mxN], out[mxN], lvl[mxN], par[mxN];
vi adj[mxN];
bool vis[mxN];

void bfs() { //for levels
    fill(vis+1, vis+n+1, 0);
    queue<int> q;
    q.push(1);
    vis[1]=1;
    while (!q.empty()) {
        int v=q.front(); q.pop();
        for (int u : adj[v])
            if (!vis[u]) {
                lvl[u]=lvl[v]+1, vis[u]=1;
                q.push(u);
            }
    }
}

void dfs(int v=1, int p=-1) { //for parent+in/out arrays
    in[v]=t++, vis[v]=1, par[v]=p;
    for (int u : adj[v])
        if (!vis[u])
            dfs(u, v);
    out[v]=t++;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n >> m;
    ff0r(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    bfs();
    while (m--) {
        int k, cmax=-1, maxnode; cin >> k;
        vi qu(k);
        ff0r(i, k) {
            cin >> qu[i];
            if (lvl[qu[i]]>cmax) {
                cmax=lvl[qu[i]];
                maxnode=qu[i];
            }
        }
        ff0r(i, k)
            if (qu[i]!=1 && qu[i]!=maxnode)
                qu[i]=par[qu[i]];
        int cnt=0;
        ff0r(i, k)
            if (in[qu[i]]<=in[maxnode] && out[qu[i]]>=out[maxnode])
                ++cnt;
        if (cnt==k)
            cout << "YES\n";
        else
            cout << "NO\n";        
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


