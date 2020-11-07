//USACO Silver February 2016 Problem 3
#include <bits/stdc++.h>
using namespace std;
//kinda like that one training website problem
//Oof messed up - I was doing dfs when I should've been doing bfs - 2nd try :c
int x, y, k, m, ans=INT_MAX, can[101][101];
set<int> pos;

ifstream fin("pails.in");
ofstream fout("pails.out");

void pour(int a, int b, int cur) {
    if ((can[a][b]>0 && cur>=can[a][b]) || cur>k)
        return;
    can[a][b]=cur;
    pos.insert(a+b);
    if (a<=y-b)
        pour(0, b+a, cur+1);
    else
        pour(a-y+b, y, cur+1);
    if (b<=x-a)
        pour(a+b, 0, cur+1);
    else
        pour(x, b-x+a, cur+1);
    pour(x, b, cur+1);
    pour(a, y, cur+1);
    pour(0, b, cur+1);
    pour(a, 0, cur+1);
}

int main(void) {
    fin >> x >> y >> k >> m;
    pour(0, 0, 0);
    for (auto it=pos.begin(); it!=pos.end(); ++it)
        ans=min(ans, abs(m-*it));
    fout << ans << '\n';
}
