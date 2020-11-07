#include <bits/stdc++.h>
using namespace std;

int n, m, ans, group[1001][1001];
string mp[1001];

void dfs(int x, int y, int num) {
    if (group[x][y]==num)
        return;
    group[x][y]=num;
    if (x>0 && mp[x-1][y]=='.')
        dfs(x-1, y, num);
    if (x<n-1 && mp[x+1][y]=='.')
        dfs(x+1, y, num);
    if (y>0 && mp[x][y-1]=='.')
        dfs(x, y-1, num);
    if (y<m-1 && mp[x][y+1]=='.')
        dfs(x, y+1, num);
}

int main(void) {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> mp[i];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) {
            if (group[i][j]>0 || mp[i][j]=='#')
                continue;
            dfs(i, j, ++ans);
        }
    cout << ans << '\n';
}
