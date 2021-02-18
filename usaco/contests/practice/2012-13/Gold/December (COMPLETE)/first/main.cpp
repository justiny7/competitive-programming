#include <bits/stdc++.h>
using namespace std;

const int mxN=3e4+1;
int n, vis[26], mat[26][26];
string s[mxN];
vector<string> ans;
struct node {
    node *to[26];
    bool en;
    node() {
        en=0;
        for (int i=0; i<26; ++i)
            to[i]=nullptr;
    }
};
node *root=new node();
inline int get(char c) {
    return (c-'a');
}
void ins(string &x, int pos=0, node *cur=root) {
    if (pos==x.size()) {
        cur->en=1;
        return;
    }
    int c=get(x[pos]);
    if (!cur->to[c])
        cur->to[c]=new node();
    ins(x, pos+1, cur->to[c]);
}
bool dfs(string &x, int pos=0, node *cur=root) {
    if (pos==x.size())
        return 1;
    if (cur->en)
        return 0;
    int c=get(x[pos]);
    for (int i=0; i<26; ++i)
        if (i^c && cur->to[i])
            mat[c][i]=1;
    return dfs(x, pos+1, cur->to[c]);
}
bool ok(int v) {
    vis[v]=1;
    for (int u=0; u<26; ++u) {
        if (u==v || !mat[v][u])
            continue;
        if (vis[u]==1 || (!vis[u] && !ok(u)))
            return 0;
    }
    vis[v]=2;
    return 1;
}

int main() {
    ifstream cin("first.in");
    ofstream cout("first.out");
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
        ins(s[i]);
    }
    for (int i=0; i<n; ++i) {
        memset(vis, 0, sizeof(vis));
        memset(mat, 0, sizeof(mat));
        if (!dfs(s[i]))
            continue;
        bool f=1;
        for (int j=0; j<26; ++j)
            if (!vis[j] && !ok(j))
                f=0;
        if (f)
            ans.push_back(s[i]);
    }
    cout << ans.size() << '\n';
    for (string x:ans)
        cout << x << '\n';
}

