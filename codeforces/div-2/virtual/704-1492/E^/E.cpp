#include <bits/stdc++.h>
using namespace std;

const int mxN=250'001;
int n, m;
vector<int> v[mxN], ans;

bool dfs(int cur=0) {
    if (cur>2)
        return 0;
    for (int i=0; i<n; ++i) {
        vector<int> here;
        int sz=0;
        for (int j=0; j<m; ++j)
            if (v[i][j]^ans[j])
                here.push_back(j), ++sz;
        if (sz>2) {
            if (sz<5) {
                for (int j:here) {
                    int orig=ans[j];
                    ans[j]=v[i][j];
                    if (dfs(cur+1))
                        return 1;
                    ans[j]=orig;
                }
            }
            return 0;
        }
    }
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        v[i].resize(m);
        for (int &j:v[i])
            cin >> j;
    }
    ans=v[0];
    if (dfs()) {
        cout << "Yes\n";
        for (int i=0; i<m; ++i)
            cout << ans[i] << " \n"[i==m-1];
    }
    else
        cout << "No\n";
}

