//USACO Silver US Open 2019 Problem 3

//Easy dfs problem - worked first try
#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;

ifstream fin("fenceplan.in");
ofstream fout("fenceplan.out");

int n, m, ans = INT_MAX, maxw = -1, maxh = -1, minw = INT_MAX, minh = INT_MAX, groups[100001], groupnum = 1;
vector<int> adj[100001];
map<int, pii> cows;

void dfs(int cur, int num) {
    if (groups[cur] == num)
        return;
    groups[cur] = num;
    int curx = cows[cur].fi, cury = cows[cur].se;
    maxw = max(maxw, curx);
    minw = min(minw, curx);
    maxh = max(maxh, cury);
    minh = min(minh, cury);
    for (int u : adj[cur])
        dfs(u, num);
}

int main(void) {
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int a, b;
        fin >> a >> b;
        cows[i] = {a, b};
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    fill(groups, groups+n+1, -1);
    for (int i = 1; i <= n; i++) {
        if (groups[i] != -1)
            continue;
        maxw = maxh = -1;
        minw = minh = INT_MAX;
        dfs(i, groupnum++);
        //for (int j = 1; j <= n; j++)
            //cout << j << ": " << groups[j] << '\n';
        //cout << '\n';
        ans = min(ans, 2*((maxw-minw)+(maxh-minh)));
    }
    fout << ans << '\n';
    return 0;
}

