#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 59;
int n;
array<long long, 2> pts[N];
bool vis[N];

inline long long sq(long long x) {
    return x * x;
}
inline long long dist(int a, int b) {
    return sq(pts[a][0] - pts[b][0]) + sq(pts[a][1] - pts[b][1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> pts[i][0] >> pts[i][1];
    int v = 1;
    vis[v] = 1;
    cout << 1;
    for (int t = 1; t < n; ++t) {
        int u = -1;
        for (int i = 1; i <= n; ++i)
            if (!vis[i] && (u < 0 || dist(v, i) > dist(v, u)))
                u = i;
        vis[v = u] = 1;
        cout << " " << v;
    }
    cout << '\n';
}
