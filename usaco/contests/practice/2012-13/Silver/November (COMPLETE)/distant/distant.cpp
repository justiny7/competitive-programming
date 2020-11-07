//Yay worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;

const int mxN=31, kx[]={0, 1, 0, -1}, ky[]={1, 0, -1, 0};
int n, a, b, dist[mxN*mxN], ans;
string mp[mxN];
struct node {
    int x, y, d;
    bool operator<(const node& a) const {
        return d>a.d;
    }
    int get() {
        return x*n+y;
    }
};
priority_queue<node> pq;

bool in(int x, int y) {
    return (x>=0 && y>=0 && x<n && y<n);
}

void dij(int x, int y) {
    int ret=0;
    memset(dist, 0x3f, sizeof(dist));
    node st{x, y, 0};
    dist[st.get()]=0;
    pq.push(st);
    while (!pq.empty()) {
        node v=pq.top(); pq.pop();
        if (dist[v.get()]!=v.d)
            continue;
        ans=max(ans, v.d);
        for (int i=0; i<4; ++i) {
            int ny=v.y+ky[i], nx=v.x+kx[i];
            if (!in(nx, ny))
                continue;
            node u{nx, ny, v.d+(mp[v.y][v.x]==mp[ny][nx]?a:b)};
            if (dist[u.get()]>u.d) {
                dist[u.get()]=u.d;
                pq.push(u);
            }
        }
    }
}

int main() {
    ifstream cin("distant.in");
    ofstream cout("distant.out");
    cin >> n >> a >> b;
    for (int i=0; i<n; ++i)
        cin >> mp[i];
    for (int x=0; x<n; ++x)
        for (int y=0; y<n; ++y)
            dij(x, y);
    cout << ans << '\n';
}

