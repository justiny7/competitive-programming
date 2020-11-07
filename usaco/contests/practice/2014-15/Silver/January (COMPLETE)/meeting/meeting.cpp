#include <bits/stdc++.h>
using namespace std;

ifstream fin("meeting.in");
ofstream fout("meeting.out");

const int mxN=101;
int n, m, adj1[mxN][mxN], adj2[mxN][mxN];
bool dp1[mxN][mxN*mxN], dp2[mxN][mxN*mxN];

int main(void) {
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        adj1[a][b]=c;
        adj2[a][b]=d;
    }
    dp1[1][0]=1, dp2[1][0]=1;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<=1e4+1; ++j) {
            if (!dp1[i][j] && !dp2[i][j])
                continue;
            for (int k=i+1; k<=n; ++k) {
                if (dp1[i][j] && adj1[i][k]>0)
                    dp1[k][j+adj1[i][k]]=1;
                if (dp2[i][j] && adj2[i][k]>0)
                    dp2[k][j+adj2[i][k]]=1;
            }
        }
    for (int i=0; i<=1e4+1; ++i) {
        if (dp1[n][i] && dp2[n][i]) {
            fout << i << '\n';
            return 0;
        }
    }
    fout << "IMPOSSIBLE\n";
}

