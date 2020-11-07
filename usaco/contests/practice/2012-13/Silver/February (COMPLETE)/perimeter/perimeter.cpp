#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//Another relatively simple problem that took very long to debug
//We tour the perimeter of the shape
ifstream fin("perimeter.in");
ofstream fout("perimeter.out");

const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};
ll n, ans, minx=1e9, miny=1e9;
map<int, map<int, bool>> have, vis[4]; //each square can be visited once in each direction

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        ll x, y;
        fin >> x >> y;
        have[x][y]=1;
        if (x<minx)
            miny=1e9;
        if (x<=minx)
            minx=x, miny=min(miny, y);
    }
    int x=minx-1, y=miny, d=0, leftcnt=0;
    vis[d][x][y]=1;
    while (1) {
        ++ans;
        //cout << x << " " << y << '\n';
        int nd=(d+1)%4;
        if (!have[x+kx[d]+kx[nd]][y+ky[d]+ky[nd]] //Conditions for turning right: there is a square directly to your right,
                && have[x+kx[nd]][y+ky[nd]]       //but not in front of you, nor in your destination square to your top right
                && !have[x+kx[d]][y+ky[d]]) {
            if (!vis[nd][x+kx[d]+kx[nd]][y+ky[d]+ky[nd]]) {
                x+=kx[d]+kx[nd], y+=ky[d]+ky[nd];
                vis[nd][x][y]=1, d=nd, leftcnt=0;
                continue;
            }
            else
                break;
        }
        if (!have[x+kx[d]][y+ky[d]]) {
            if (!vis[d][x+kx[d]][y+ky[d]]) {
                x+=kx[d], y+=ky[d];
                vis[d][x][y]=1, leftcnt=0;
                continue;
            }
            else
                break;
        }
        d=(d+4-1)%4;
        ++leftcnt;
        if (leftcnt==4) //if you turn left 4 times in succession without moving, then you're done
            break;
    }
    fout << ans << '\n';
    //for (int i=60; i>40; --i) {
        //for (int j=40; j<60; ++j)
            //cout << ((have[j][i])?'#':'.');
        //cout << '\n';
    //}
}
