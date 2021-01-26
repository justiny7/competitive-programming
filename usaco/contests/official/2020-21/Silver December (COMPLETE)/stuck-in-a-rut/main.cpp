#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e3+1;
int n, c[2], en[2][mxN];
map<pii, int> mp;
vector<int> adj[mxN];
vector<pii> v[2];
struct event {
    int x, y, t;
    pii stopper, stoppee;
    bool operator<(const event &o) const {
        return t<o.t;
    }
};
vector<event> events;

int dfs(int v) {
    int c=adj[v].size();
    for (int u:adj[v])
        c+=dfs(u);
    return c;
}

int main() {
    memset(en, -1, sizeof(en));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i) {
        int a, b; char ch;
        cin >> ch >> a >> b;
        v[(ch=='N')].eb(a, b);
        ++c[(ch=='N')];
        mp[pii(a, b)]=i;
    }
    for (int i=0; i<c[0]; ++i)
        for (int j=0; j<c[1]; ++j) {
            pii a=v[0][i], b=v[1][j];
            if (a.fi<b.fi && a.se>b.se) {
                int dx=b.fi-a.fi, dy=a.se-b.se;
                if (dx<dy)
                    events.eb(event{b.fi, a.se, dy, pii(0, i), pii(1, j)});
                else if (dx>dy)
                    events.eb(event{b.fi, a.se, dx, pii(1, j), pii(0, i)});
            }
        }
    sort(events.begin(), events.end());
    for (int i=0; i<events.size(); ++i) {
        pii dead=events[i].stoppee, alive=events[i].stopper;
        if (~en[dead.fi][dead.se])
            continue;
        if (~en[alive.fi][alive.se]) {
            if (alive.fi && en[alive.fi][alive.se]<events[i].y)
                continue;
            else if (!alive.fi && en[alive.fi][alive.se]<events[i].x)
                continue;
        }
        en[dead.fi][dead.se]=(dead.fi?events[i].y:events[i].x);
        adj[mp[v[alive.fi][alive.se]]].eb(mp[v[dead.fi][dead.se]]);
        //cout << "For real, cow at (" << v[alive.fi][alive.se].fi << " " << v[alive.fi][alive.se].se << ") stops cow at (" << v[dead.fi][dead.se].fi << " " << v[dead.fi][dead.se].se << ")\n";
        //cout << "Cow at ID " << mp[v[alive.fi][alive.se]] << " stops cow at ID " << mp[v[dead.fi][dead.se]] << '\n';
    }
    for (int i=0; i<n; ++i)
        cout << dfs(i) << '\n';
}

