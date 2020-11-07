#include <bits/stdc++.h>
using namespace std;

const int mxN=11, mxK=1e3+1;
int n, m, k, w, tot;
string b[mxK][mxN];
bool vis[mxK];
struct node {
    int v, p, x;
    bool operator<(const node& o) const {
        return x>o.x;
    }
};
vector<node> ans;
priority_queue<node> pq;

int diff(int x, int y) {
    int ret=0;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            ret+=(b[x][i][j]!=b[y][i][j]);
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> w;
    for (int i=0; i<k; ++i)
        for (int j=0; j<n; ++j)
            cin >> b[i][j];
    for (int i=0; i<k; ++i)
        pq.push(node{i, -1, n*m});
    while (pq.size()) {
        node c=pq.top(); pq.pop();
        if (vis[c.v])
            continue;
        vis[c.v]=1, tot+=c.x;
        ans.push_back(c);
        for (int i=0; i<k; ++i)
            if (!vis[i])
                pq.push(node{i, c.v, diff(c.v, i)*w});
    }
    cout << tot << '\n';
    for (auto g:ans)
        cout << g.v+1 << " " << g.p+1 << '\n';
}

