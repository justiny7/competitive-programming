//USACO Bronze US Open 2015 Problem 4
#include <bits/stdc++.h>
using namespace std;

int n;
string farm[19], cur;
set<string> ans2;
map<int, set<string>> ans;

bool in(int i, int j) {
    return (i>=0 && j>=0 && i<n && j<n);
}

void dfs(int i=0, int j=0) {
    cur+=farm[i][j];
    if (i+j==n-1) {
        ans[i].insert(cur);
        cur.pop_back();
        return;
    }
    if (in(i+1, j))
        dfs(i+1, j);
    if (in(i, j+1))
        dfs(i, j+1);
    cur.pop_back();
}

void dfs2(int i=n-1, int j=n-1) {
    cur+=farm[i][j];
    if (i+j==n-1) {
        if (ans[i].count(cur))
            ans2.insert(cur);
        cur.pop_back();
        return;
    }
    if (in(i-1, j))
        dfs2(i-1, j);
    if (in(i, j-1))
        dfs2(i, j-1);
    cur.pop_back(); 
}

int main(void) {
    freopen("palpath.in", "r", stdin);
    freopen("palpath.out", "w", stdout);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> farm[i];
    dfs();
    dfs2();
    cout << ans2.size() << '\n';
}
