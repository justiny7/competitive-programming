#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=2e5+1;
int n, c, a[mxN], b[mxN], d[mxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool vis[mxN];

int st(int s, int f) {
    return abs(a[s]-a[f]);
}

int el(int s, int f) {
    return c+abs(b[s]-b[f]);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> c;
    for (int i=1; i<n; ++i) {
        int k;
        cin >> k;
        a[i]=a[i-1]+k;
    }
    for (int i=1; i<n; ++i) {
        int k;
        cin >> k;
        b[i]=b[i-1]+k;
    }
    fill(d, d+n, INT_MAX);
    d[0]=0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int t=pq.top().se;
        pq.pop();
        if (vis[t])
            continue;
        vis[t]=1;
        for (int i=0; i<n; ++i) {
            if (vis[i])
                continue;
            int di=min(st(i, t), el(i, t));
            if (d[t]+di<d[i]) {
                d[i]=d[t]+di;
                pq.push({d[i], i});
            }
        }
    }
    for (int i=0; i<n; ++i) {
        if (i>0)
            cout << " ";
        cout << d[i];
    }
    cout << '\n';
}
