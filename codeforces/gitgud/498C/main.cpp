#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=101, mxA=1e5+1, mxV=5e3+1;
int n, m, prime[mxA];
set<pii> good;
vector<int> primes;
vector<pii> nodes;

//Dinic's
struct Edge {
    int v, flow, c, rev;
};
int lvl[mxV], start[mxV];
vector<Edge> adj[mxV];

void add(int u, int v, int cap) {
    Edge a{v, 0, cap, (int)adj[v].size()};
    Edge b{u, 0, 0, (int)adj[u].size()};
    adj[u].pb(a);
    adj[v].pb(b);
}
bool bfs(int src=0, int snk=mxV-1) {
    fill(lvl, lvl+snk+1, -1);
    lvl[src]=0;
    queue<int> q;
    q.push(src);
    while (q.size()) {
        int t=q.front(); q.pop();
        for (auto &u:adj[t])
            if (lvl[u.v]<0 && u.flow<u.c)
                lvl[u.v]=lvl[t]+1, q.push(u.v);
    }
    return (~lvl[snk]);
}
int send(int cur, int flo, int snk=mxV-1) {
    if (cur==snk)
        return flo;
    while (start[cur]<adj[cur].size()) {
        Edge &e=adj[cur][start[cur]];
        if (lvl[e.v]==lvl[cur]+1 && e.flow<e.c) {
            int cmin=min(flo, e.c-e.flow), tflo=send(e.v, cmin);
            if (tflo>0) {
                e.flow+=tflo;
                adj[e.v][e.rev].flow-=tflo;
                return tflo;
            }
        }
        ++start[cur];
    }
    return 0;
}
int dinic() {
    int tot=0;
    while (bfs()) {
        fill(start, start+mxV, 0);
        while (int f=send(0, 1e6))
            tot+=f;
    }
    return tot;
}

void sieve() {
    for (int i=2; i<mxA; ++i)
        prime[i]=1;
    for (int i=2; i*i<mxA; ++i)
        if (prime[i]) {
            primes.pb(i);
            for (int j=i*i; j<mxA; j+=i)
                prime[j]=0;
        }
}

int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        int a, j=0; cin >> a;
        while (a>1) {
            if (a%primes[j]==0)
                a/=primes[j], nodes.pb(pii(primes[j], i));
            else
                ++j;
            if (j==primes.size()) {
                nodes.pb(pii(a, i));
                break;
            }
        }
    }
    for (int i=0; i<m; ++i) {
        int x, y;
        cin >> x >> y;
        pii p=minmax(x, y);
        good.insert(p);
    }
    for (int i=0; i<nodes.size(); ++i) {
        if (nodes[i].se&1)
            add(0, i+1, 1);
        else
            add(i+1, mxV-1, 1);
        for (int j=i+1; j<nodes.size(); ++j) {
            pii p=minmax(nodes[i].se, nodes[j].se);
            if (good.count(p) && nodes[i].fi==nodes[j].fi) {
                if (nodes[i].se&1)
                    add(i+1, j+1, 1);
                else
                    add(j+1, i+1, 1);
            }
        }
    }
    cout << dinic() << '\n';
}

