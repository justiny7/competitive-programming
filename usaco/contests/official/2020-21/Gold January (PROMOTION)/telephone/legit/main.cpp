#include <bits/stdc++.h>
using namespace std;
using pi=pair<int, int>;

const int mxN=5e4+1, mxK=51;
int n, k, breed[mxN], dist[mxN];
vector<int> cows[mxK], adj[mxN];
priority_queue<pi, vector<pi>, greater<pi>> pq;

int main() {
    memset(dist, 0x3f, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> breed[i];
        cows[breed[i]].push_back(i);
    }
    for (int i=1; i<=k; ++i) {
        string s; cin >> s;
        for (int j=1; j<=k; ++j) {
            if (s[j-1]=='0')
                continue;
            if (breed[n]^j) {
                for (int l:cows[i]) {
                    auto it=upper_bound(cows[j].begin(), cows[j].end(), l);
                    if (it!=cows[j].end())
                        adj[l].push_back(*it);
                    it=lower_bound(cows[j].begin(), cows[j].end(), l);
                    if (it!=cows[j].begin())
                        adj[l].push_back(*prev(it));
                }
            }
            else {
                for (int l:cows[i])
                    adj[l].push_back(n);
            }
        }
    }
    dist[1]=0;
    pq.emplace(0, 1);
    while (pq.size()) {
        int d, v;
        tie(d, v)=pq.top(); pq.pop();
        if (dist[v]^d)
            continue;
        for (int u:adj[v]) {
            int nd=d+abs(u-v);
            if (dist[u]>nd) {
                dist[u]=nd;
                pq.emplace(nd, u);
            }
        }
    }
    cout << (dist[n]==0x3f3f3f3f?-1:dist[n]) << '\n';
}

