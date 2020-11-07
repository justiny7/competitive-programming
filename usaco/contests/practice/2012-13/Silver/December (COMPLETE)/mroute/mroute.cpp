//Yay basically first try (typoed mxN=5-1 instead of 501 xd)
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ld=long double;

const int mxN=501;
int n, m;
ld x, dist[mxN];
ld get(ld d, ld c) {
    if (!d)
        return 0;
    return x/c+d;
}
struct edge {
    int to;
    ld l, cap;
    edge(int to, ld l, ld cap):to(to), l(l), cap(cap) {}
};
struct node {
    int x=1;
    ld dst=0, cap=2e9;
    node() {}
    node(int x, ld dst, ld cap):x(x), dst(dst), cap(cap) {}
    bool operator<(const node& s) const {
        return get(dst, cap)>get(s.dst, s.cap);
    }
};
vector<edge> adj[mxN];
priority_queue<node> pq;

int main() {
    ifstream cin("mroute.in");
    ofstream cout("mroute.out");
    cin >> n >> m >> x;
    while (m--) {
        int a, b;
        ld c, d;
        cin >> a >> b >> c >> d;
        adj[a].pb(edge(b, c, d));
        adj[b].pb(edge(a, c, d));
    }
    fill(dist+1, dist+n+1, 1e18);
    dist[1]=0;
    pq.push(node());
    while (pq.size()) {
        int v=pq.top().x;
        ld d=pq.top().dst, c=pq.top().cap;
        pq.pop();
        if (dist[v]!=get(d, c))
            continue;
        for (edge u:adj[v]) {
            node nxt(u.to, d+u.l, min(c, u.cap));
            ld a=get(nxt.dst, nxt.cap);
            if (a<dist[u.to]) {
                dist[u.to]=a;
                pq.push(nxt);
            }
        }
    }
    cout << (long long)dist[n] << '\n';
}

