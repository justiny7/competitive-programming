#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 69;
int n, nxt[N], prv[N];
array<int, 4> a[N];
priority_queue<array<int, 5>, vector<array<int, 5>>, greater<array<int, 5>>> pq;
bool vis[N];

void rem(int x) {
    prv[nxt[x]] = prv[x];
    nxt[prv[x]] = nxt[x];
}
array<int, 5> dif(int q, int r) {
    return {abs(a[q][0] - a[r][0]), abs(a[q][1] - a[r][1]), abs(a[q][2] - a[r][2]), q, r};
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        a[i][3] = i + 1;
        nxt[i] = (i + 1) % n;
        prv[i] = (i + n - 1) % n;
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        pq.push(dif(i, nxt[i]));
    while (pq.size()) {
        int u = pq.top()[3], v = pq.top()[4];
        pq.pop();
        if (vis[u] || vis[v])
            continue;
        cout << a[u][3] << " " << a[v][3] << '\n';
        vis[u] = vis[v] = 1;
        rem(u); rem(v);
        pq.push(dif(prv[u], nxt[v]));
    }
}
