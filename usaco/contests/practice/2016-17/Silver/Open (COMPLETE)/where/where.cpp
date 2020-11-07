//USACO Silver US Open 2017 Problem 3

#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("where.in");
ofstream fout("where.out");

struct rect {
    int x1, x2, y1, y2;
};

int n, ans;
string cows[21];
vector<rect> pcl;
bool vis[21][21];

void dfs(int x, int y, int w1, int h1, int w2, int h2, char c) {
    vis[x][y]=1;
    if (x>w1 && !vis[x-1][y] && cows[x-1][y]==c)
        dfs(x-1, y, w1, h1, w2, h2, c);
    if (x<w2 && !vis[x+1][y] && cows[x+1][y]==c)
        dfs(x+1, y, w1, h1, w2, h2, c);
    if (y>h1 && !vis[x][y-1] && cows[x][y-1]==c)
        dfs(x, y-1, w1, h1, w2, h2, c);
    if (y<h2 && !vis[x][y+1] && cows[x][y+1]==c)
        dfs(x, y+1, w1, h1, w2, h2, c);
}

bool works(int w1, int h1, int w2, int h2) {
    int let[26], lc=0; //letter count
    fill(let, let+26, 0);
    for (int i=w1; i<=w2; i++)
        for (int j=h1; j<=h2; j++)
            vis[i][j]=0;
    for (int i=w1; i<=w2; i++)
        for (int j=h1; j<=h2; j++)
            if (!vis[i][j]) {
                let[cows[i][j]-'A']++;
                if (let[cows[i][j]-'A']==1)
                    lc++;
                dfs(i, j, w1, h1, w2, h2, cows[i][j]);
            }
    if (lc!=2)
        return false;
    bool one=0, two=0;
    for (int i=0; i<26; i++) {
        if (let[i]==1)
            one=1;
        if (let[i]>1)
            two=1;
    }
    return (one && two);
}

bool works2(int ind) {
    for (int i=0; i<pcl.size(); i++) {
        if (i==ind)
            continue;
        if (pcl[ind].x1>=pcl[i].x1 && pcl[ind].x2<=pcl[i].x2 && pcl[ind].y1>=pcl[i].y1 && pcl[ind].y2<=pcl[i].y2)
            return false;
    }
    return true;
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; i++)
        fin >> cows[i];
    for (int a=0; a<n; a++)
        for (int b=0; b<n; b++)
            for (int c=a; c<n; c++)
                for (int d=b; d<n; d++)
                    if (works(a, b, c, d)) {
                        rect x={a, c, b, d};
                        pcl.pb(x);
                    }
    //cout << pcl.size() << '\n';
    for (int i=0; i<pcl.size(); i++) {
        //cout << pcl[i].x1 << " " << pcl[i].x2 << " " << pcl[i].y1 << " " << pcl[i].y2 << '\n';
        if (works2(i))
            ans++;
    }
    fout << ans << '\n';
    return 0;
}
