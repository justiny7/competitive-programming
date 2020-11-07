//Got it after using Prim's instead of Kruskal's 
//(and looking at sol to see if MST really was the right approach xd)
#include <bits/stdc++.h>
using namespace std;

const int mxN=7501, A=2019201913, B=2019201949, M=2019201997;
int n, k, dist[mxN];
bool vis[mxN];

int get(int a, int b) {
    if (a>b)
        swap(a, b);
    return ((1LL*a*A)+(1LL*b*B))%M;
}

int main() {
    ifstream cin("walk.in");
    ofstream cout("walk.out");
    cin >> n >> k;
    memset(dist, 0x7f, sizeof(dist));
    for (int t=0; t<n; ++t) {
        int v=-1;
        for (int i=1; i<=n; ++i)
            if (!vis[i] && (v<0 || dist[i]<dist[v]))
                v=i;
        vis[v]=1;
        for (int i=1; i<=n; ++i)
            if (!vis[i] && i^v)
                dist[i]=min(dist[i], get(i, v));
    }
    sort(dist+1, dist+n+1);
    cout << dist[n-k+1] << '\n';
}

