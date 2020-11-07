//USACO US Open 2017 Problem 2

//Prob brute force w/ a bit of optimization
#include <bits/stdc++.h>
using namespace std;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

int n, m, ans, p[501][51], s[501][51];

int convert(char c) {
    if (c=='A')
        return 0;
    if (c=='C')
        return 1;
    if (c=='G')
        return 2;
    return 3;
}

bool works(int a, int b, int c) {
    bool taken[64]; //only 4^3=64 possible combinations
    memset(taken, 0, sizeof(taken));
    for (int i=0; i<n; i++)
        taken[s[i][a]*16+s[i][b]*4+s[i][c]]=1;
    for (int i=0; i<n; i++)
        if (taken[p[i][a]*16+p[i][b]*4+p[i][c]])
            return false;
    return true;
}

int main(void) {
    fin >> n >> m;
    string st;
    for (int i=0; i<n; i++) {
        fin >> st;
        for (int j=0; j<m; j++)
            s[i][j]=convert(st[j]);
    }
    for (int i=0; i<n; i++) {
        fin >> st;
        for (int j=0; j<m; j++)
            p[i][j]=convert(st[j]);
    }
    for (int a=0; a<m; a++)
        for (int b=a+1; b<m; b++)
            for (int c=b+1; c<m; c++)
                if (works(a, b, c))
                    ans++;
    fout << ans << '\n';
    return 0;
}
