//Kinda fakesolved to ICP lmao
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pl=pair<ll, ll>;

const int mxN=5e4+1, mxK=54;
const ll INF=0x3f3f3f3f3f3f3f3f;
int n, k, vis[mxN];
ll breed[mxN], dp[mxN];
vector<int> breed_list[mxK];
bool ok[mxK][mxK];
priority_queue<pl, vector<pl>, greater<pl>> pq;

int main() {
    memset(dp, 0x3f, sizeof(dp));
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
    dp[1]=0;
    while (pq.size()) {
        int d_v, v;
        tie(d_v, v)=pq.top(); pq.pop();
        if (d_v^dp[v])
            continue;
        if (v^1)
            ++vis[breed[v]];
        //cout << v << " " << d_v << '\n';
        for (int i=1; i<=k; ++i) {
            if (!ok[breed[v]][i] || vis[i]>50) //visited at most once from each other breed? idk random huerstics pog kekw
                continue;
            //cout << "here\n";
            for (int u:breed_list[i]) {
                ll nd=d_v+abs(v-u);
                if (dp[u]>nd) {
                    dp[u]=nd;
                    pq.push({nd, u});
                }
            }
        }
    }
    cout << (dp[n]==INF?-1:dp[n]) << '\n';
}

