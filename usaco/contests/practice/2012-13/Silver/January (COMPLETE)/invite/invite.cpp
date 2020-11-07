#include <bits/stdc++.h>
using namespace std;

ifstream fin("invite.in");
ofstream fout("invite.out");

const int mxG=250001, mxN=1e6+1;
int n, g, ans;
vector<set<int>> grps;
bool vis[mxG], vis2[mxN];

int main() {
    fin >> n >> g;
    for (int i=0; i<n; ++i) {
        set<int> temp;
        int s; fin >> s;
        for (int j=0; j<s; ++j) {
            int a; fin >> a;
            temp.insert(a);
        }
        grps.push_back(temp);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        ++ans;
        int t=q.front(); q.pop();
        for (int i=0; i<g; ++i) {
            if (vis[i])
                continue;
            if (grps[i].count(t))
                grps[i].erase(t);
            if (grps[i].size()==1) {
                vis[i]=1;
                int c=*(grps[i].begin());
                if (!vis2[c])
                    vis2[c]=1, q.push(c);
            }
        }
    }
    fout << ans << '\n';
}

