#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowroute.in");
ofstream fout("cowroute.out");

int a, b, n, ans=INT_MAX, cost[501];
vector<int> routes[501];

int main(void) {
    fin >> a >> b >> n;
    for (int i=0; i<n; ++i) {
        int c, k;
        fin >> c >> k;
        cost[i]=c;
        routes[i].resize(k);
        for (int j=0; j<k; ++j)
            fin >> routes[i][j];
    }
    for (int i=0; i<n; ++i) {
        bool f1=0, f2=0;
        for (int& j:routes[i]) {
            if (j==a)
                f1=1;
            if (j==b && f1)
                f2=1;
        }
        if (f1 && f2)
            ans=min(ans, cost[i]);
    }
    for (int i=0; i<n; ++i) {
        set<int> cur;
        bool f=0;
        for (int j=0; j<routes[i].size(); ++j) {
            if (routes[i][j]==a)
                f=1;
            else if (f)
                cur.insert(routes[i][j]);
        }
        if (cur.empty())
            continue;
        for (int j=0; j<n; ++j) {
            if (j==i)
                continue;
            bool f1=0, f2=0;
            for (int l=0; l<routes[j].size(); ++l) {
                if (cur.count(routes[j][l]))
                    f1=1;
                if (routes[j][l]==b && f1)
                    f2=1;
            }
            if (f1 && f2)
                ans=min(ans, cost[i]+cost[j]);
        }
    }
    if (ans==INT_MAX) {
        fout << "-1\n";
        return 0;
    }
    fout << ans << '\n';
}

