#include <bits/stdc++.h>
using namespace std;
using pi=pair<int, int>;

const int mxN=5e4+1, mxK=51, INF=0x3f3f3f3f;
int n, k, breed[mxN], dist[mxN];
vector<int> breed_list[mxK];
bool ok[mxK][mxK];
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main() {
    memset(dist, 0x3f, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> breed[i];
        breed_list[breed[i]].push_back(i);
    }
    for (int i=1; i<=k; ++i) {
        string s; cin >> s;
        for (int j=1; j<=k; ++j)
            ok[i][j]=bool(s[j-1]-'0');
    }
    pq.emplace(0, 1);
    dist[1]=0;
    while (pq.size()) {
        int d, v;
        tie(d, v)=pq.top(); pq.pop();
        if (d^dist[v])
            continue;
        for (int i=1; i<=k; ++i) {
            if (!ok[breed[v]][i] || breed_list[i].empty())
                continue;
            for (int t=0; t<3; ++t) {
                int u;
                if (t==0) {
                    auto it=lower_bound(breed_list[i].begin(), breed_list[i].end(), v);
                    if (it!=breed_list[i].begin())
                        --it;
                    else
                        continue;
                    u=*it;
                }
                else if (t==1) {
                    auto it=upper_bound(breed_list[i].begin(), breed_list[i].end(), v);
                    if (it==breed_list[i].end())
                        continue;
                    u=*it;
                }
                else
                    u=breed_list[i].back();
                int nd=d+abs(v-u);
                if (dist[u]>nd) {
                    dist[u]=nd;
                    pq.emplace(nd, u);
                }
            }
        }
    }
    cout << (dist[n]==INF?-1:dist[n]) << '\n';
}

