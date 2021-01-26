//YES worked first try
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pi=pair<int, int>;

const int mxN=1e5+1, mxK=2e5+1;
int n, k, pos[mxN], ans[mxN];
set<int> vis[mxN];
vector<pi> vis2[mxN];
vector<vector<int>> cycles;
ll m;
pi ops[mxK];
bool seen[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> m;
    for (int i=1; i<=n; ++i)
        pos[i]=i, vis[i].insert(i), vis2[i].emplace_back(0, i);
    for (int i=1; i<=k; ++i) {
        int a, b;
        cin >> a >> b;
        swap(pos[a], pos[b]);
        vis[pos[a]].insert(a);
        vis[pos[b]].insert(b);
        vis2[pos[a]].emplace_back(i, a);
        vis2[pos[b]].emplace_back(i, b);
    }
    for (int i=1; i<=n; ++i) {
        //cout << "we're at cow " << i << '\n';
        //for (int j:vis[i])
            //cout << j << " ";
        //cout << '\n';
        //for (pi p:vis2[i])
            //cout << p.first << " " << p.second << '\n';
        //cout << '\n';
        if (seen[i])
            continue;
        vector<int> here;
        int v=i;
        while (!seen[v])
            here.push_back(v), seen[v]=1, v=pos[v];
        reverse(here.begin(), here.end());
        cycles.push_back(here);
    }
    for (auto cur:cycles) {
        map<int, int> active;
        int sz=cur.size(), len=(int)(m/(ll)k), ovr=(int)(m%(ll)k);
        //cout << "SZ: " << sz << "\tOVR: " << ovr << '\n';
        if (len>=sz) {
            set<int> all;
            for (int j:cur)
                for (int k:vis[j])
                    all.insert(k);
            for (int j:cur)
                ans[j]=all.size();
            continue;
        }
        for (int i=0; i<sz*2-1; ++i) {
            for (int j:vis[cur[i%sz]])
                ++active[j];
            if (i>=len) {
                for (int j:vis[cur[(i-len)%sz]]) {
                    --active[j];
                    if (!active[j])
                        active.erase(j);
                }
            }
            if (i>=len-1) {
                for (pi p:vis2[cur[(i+1)%sz]]) {
                    if (p.first>ovr)
                        break;
                    ++active[p.second];
                }
                //for (int j=0; j<vis2[cur[(i+1)%sz]].size(); ++j)
                ans[cur[(i-len+1)%sz]]=active.size();
                //cout << "pos: " << i << "\tat: " << cur[i%sz] << '\n';
                //cout << "this is for " << cur[(i-len+1)%sz] << '\n';
                //for (pi p:active)
                    //cout << p.first << " ";
                //cout << '\n';
                for (pi p:vis2[cur[(i+1)%sz]]) {
                    if (p.first>ovr)
                        break;
                    --active[p.second];
                    if (!active[p.second])
                        active.erase(p.second);
                }
            }
        }
    }
    for (int i=1; i<=n; ++i)
        cout << ans[i] << '\n';
}

