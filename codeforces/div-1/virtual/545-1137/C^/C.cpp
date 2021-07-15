#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, D = 51;
int n, m, d, ans, scc_, ck = 1, scc[N * D], dp[N * D], vis[N * D], state[N * D];
vector<int> adj[N], radj[N], tadj[N * D];
stack<int> ord, st;
string ok[N];

void dfs_ord(int sx) {
    st.push(sx);

    while (st.size()) {
        int x = st.top(); st.pop();

        if (state[x] == 1) {
            state[x] = 2;
            ord.push(x);
        }
        else if (!state[x]) {
            state[x] = 1;
            st.push(x);

            int v = x / d, c = x % d, nc = (c + 1) % d;
            for (int u : adj[v])
                if (!state[u * d + nc])
                    st.push(u * d + nc);
        }
    }
}
void dfs_scc(int sx) {
    st.push(sx);

    while (st.size()) {
        int x = st.top(); st.pop();
        if (~scc[x])
            continue;

        scc[x] = scc_;

        int v = x / d, c = x % d, nc = (c + d - 1) % d;
        if (vis[v] != ck && ok[v][c] == '1') {
            vis[v] = ck;
            ++dp[scc_];
        }

        for (int u : radj[v])
            if (scc[u * d + nc] < 0)
                st.push(u * d + nc);
    }
}

void dfs_ans(int s) {
    vis[s] = ck;

    int add = 0;
    for (int u : tadj[s]) {
        if (vis[u] != ck)
            dfs_ans(u);
        add = max(add, dp[u]);
    }

    ans = max(ans, dp[s] += add);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> d;
    while (m--) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
        cin >> ok[i];

    memset(scc, -1, sizeof(scc));
    for (int i = 0; i < n * d; ++i)
        if (!state[i])
            dfs_ord(i);
    while (ord.size()) {
        if (scc[ord.top()] < 0) {
            dfs_scc(ord.top());
            ++scc_, ++ck;
        }
        ord.pop();
    }

    for (int i = 0; i < n * d; ++i) {
        int v = i / d, c = i % d, nc = (c + 1) % d;
        for (int u : adj[v])
            if (scc[i] != scc[u * d + nc])
                tadj[scc[i]].push_back(scc[u * d + nc]);
    }

    dfs_ans(scc[0]);

    cout << ans << '\n';
}
