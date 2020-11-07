//USACO Silver January 2016 Problem 3

#include <bits/stdc++.h>
using namespace std;

ifstream fin("gates.in");
ofstream fout("gates.out");

int n, t, b, l, r, group[2001][2001], gc;
bool field[2001][2001];
string s;

void dfs(int x, int y, int num) {
    if (group[x][y] || field[x][y])
        return;
    group[x][y]=num;
    if (x>0 && !field[x-1][y])
        dfs(x-1, y, num);
    if (x<r && !field[x+1][y])
        dfs(x+1, y, num);
    if (y>0 && !field[x][y-1])
        dfs(x, y-1, num);
    if (y<t && !field[x][y+1])
        dfs(x, y+1, num);
}

int main(void) {
    fin >> n >> s;
    b=count(s.begin(), s.end(), 'S');
    t=count(s.begin(), s.end(), 'N')+b;
    l=count(s.begin(), s.end(), 'W');
    r=count(s.begin(), s.end(), 'E')+l;
    b*=2, t*=2, l*=2, r*=2;
    r++, t++;
    int cx=l, cy=b;
    //cout << b << " " << t << " " << l << " " << r << '\n';
    field[cx][cy]=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) {
            if (s[i]=='N')
                cy++;
            if (s[i]=='S')
                cy--;
            if (s[i]=='E')
                cx++;
            if (s[i]=='W')
                cx--;
            field[cx][cy]=1;
        }
    }
    for (int i=0; i<=r; i++)
        for (int j=0; j<=t; j++)
            if(group[i][j]==0 && !field[i][j])
                dfs(i, j, ++gc);
    /*for (int i=0; i<=r; i++) {
        for (int j=0; j<=t; j++)
            cout << group[i][j];
        cout << '\n';
    }*/
    fout << max(0, gc-1) << '\n';
}
