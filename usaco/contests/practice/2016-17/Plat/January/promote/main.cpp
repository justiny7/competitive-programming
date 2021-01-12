//Yay worked second try after changing swap(cur, here) to cur.swap(here)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int mxN=1e5+1;
int n, p[mxN], ans[mxN];
vector<int> adj[mxN];

oset<int> dfs(int v=1) {
    oset<int> here;
    here.insert(p[v]);
    for (int u:adj[v]) {
        oset<int> cur=dfs(u);
        if (cur.size()>here.size())
            cur.swap(here);
        for (int i:cur)
            here.insert(i);
    }
    ans[v]=here.size()-here.order_of_key(p[v])-1;
    return here;
}

int main() {
    ifstream cin("promote.in");
    ofstream cout("promote.out");
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> p[i];
    for (int i=2; i<=n; ++i) {
        int x; cin >> x;
        adj[x].push_back(i);
    }
    dfs();
    for (int i=1; i<=n; ++i)
        cout << ans[i] << '\n';
}

