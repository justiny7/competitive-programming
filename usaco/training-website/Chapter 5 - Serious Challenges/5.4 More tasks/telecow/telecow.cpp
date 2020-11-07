/*
ID: justiny7
LANG: C++11
TASK: telecow
*/

//Min cut
//Ahh it's so messy - yay got it fourth try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

struct Edge {
    int v, flow, c, rev;
};

const int mxN=210, INF=1e9+7; //v*2=in-node, v*2+1=out-node
int n, m, source, sink, lvl[mxN], start[mxN];
vector<vector<Edge>> adj(mxN), orig(mxN);

void add(int u, int v, int cap) {
    Edge a{v, 0, cap, (int)adj[v].size()};
    Edge b{u, 0, 0, (int)adj[u].size()};
    adj[u].pb(a);
    adj[v].pb(b);
}

bool bfs() {
    memset(lvl, -1, sizeof(lvl));
    lvl[source]=0;
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
        int t=q.front(); q.pop();
        for (auto& u:adj[t])
            if (lvl[u.v]<0 && u.flow<u.c) {
                lvl[u.v]=lvl[t]+1;
                q.push(u.v);
            }
    }
    return (lvl[sink]>=0);
}

int send(int cur, int flo) {
    if (cur==sink)
        return flo;
    while (start[cur]<adj[cur].size()) {
        Edge& e=adj[cur][start[cur]];
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
        memset(start, 0, sizeof(start));
        while (int f=send(source, INF))
            tot+=f;
    }
    return tot;
}

int main() {
    ifstream cin("telecow.in");
    ofstream cout("telecow.out");
    cin >> n >> m >> source >> sink;
    source=(source-1)*2+1, sink=(sink-1)*2;
    for (int i=0; i<n; ++i)
        add(i*2, i*2+1, 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        add(a*2+1, b*2, INF*2);
        add(b*2+1, a*2, INF*2);
    }
    orig=adj;
    int mflo=dinic();
    bool f=1;
    cout << mflo << '\n';
    for (int i=0; i<n; ++i) {
        Edge& e=adj[i*2][0];
        if (i*2==sink || i*2+1==source || !e.flow)
            continue;
        //cout << "JKLsdhf " <<i+1 << '\n';
        //for (int i=0; i<n; ++i)
            //cout << i+1 << ": " << adj[i*2][0].flow << '\n';
        //cout << '\n';
        adj=orig;
        e.c=0;
        //cout << dinic() << '\n';
        if (dinic()==mflo-1) {
            if (!f)
                cout << " ";
            cout << i+1;
            f=0;
            orig[i*2][0].c=0, --mflo;
        }
        if (!mflo)
            break;
    }
    cout << '\n';
}


