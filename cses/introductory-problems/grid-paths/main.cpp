#include <bits/stdc++.h>
#define pb push_back
#define ppb pop_back
using namespace std;

string s, cur;
vector<string> paths;
bool vis[7][7];
int ans, a; //a=debug

void gen(int x, int y) {a++;
    //cout<<cur<<'\n';
    if (x==0 && y==6) {
        if (cur.length()==48)
            paths.push_back(cur);
        return;
    }
    if (cur.length()>48)
        return;
    if (x+1<7 && !vis[y][x+1]) {
        if (x+2<7 && !vis[y][x+2]) {
            vis[y][x+1]=1;
            cur.pb('R');
            gen(x+1, y);
            cur.ppb();
            vis[y][x+1]=0;
        }
        else if (y+1<7 && y-1>=0 && (!vis[y+1][x+1] ^ !vis[y-1][x+1])) {
            vis[y][x+1]=1;
            cur.pb('R');
            gen(x+1, y);
            cur.ppb();
            vis[y][x+1]=0;
        }
        else if (y+1>=7 && !vis[y-1][x+1]) {
            vis[y][x+1]=1;
            cur.pb('R');
            gen(x+1, y);
            cur.ppb();
            vis[y][x+1]=0;
        }
        else if (y-1<0 && !vis[y+1][x+1]) {
            vis[y][x+1]=1;
            cur.pb('R');
            gen(x+1, y);
            cur.ppb();
            vis[y][x+1]=0;
        }
    }
    if (x-1>=0 && !vis[y][x-1]) {
        if (x-2>=0 && !vis[y][x-2]) {
            vis[y][x-1]=1;
            cur.pb('L');
            gen(x-1, y);
            cur.ppb();
            vis[y][x-1]=0;
        }
        else if (y+1<7 && y-1>=0 && (!vis[y+1][x-1] ^ !vis[y-1][x-1])) {
            vis[y][x-1]=1;
            cur.pb('L');
            gen(x-1, y);
            cur.ppb();
            vis[y][x-1]=0;
        }
        else if (y+1>=7 && !vis[y-1][x-1]) {
            vis[y][x-1]=1;
            cur.pb('L');
            gen(x-1, y);
            cur.ppb();
            vis[y][x-1]=0;
        }
        else if (y-1<0 && !vis[y+1][x-1]) {
            vis[y][x-1]=1;
            cur.pb('L');
            gen(x-1, y);
            cur.ppb();
            vis[y][x-1]=0;
        }
        else if (y==6 && x-1==0 && cur.length()==47) {
            vis[y][x-1]=1;
            cur.pb('L');
            gen(x-1, y);
            cur.ppb();
            vis[y][x-1]=0;
        }
    }
    if (y+1<7 && !vis[y+1][x]) {
        if (y+2<7 && !vis[y+2][x]) {
            vis[y+1][x]=1;
            cur.pb('D');
            gen(x, y+1);
            cur.ppb();
            vis[y+1][x]=0;
        }
        else if (x+1<7 && x-1>=0 && (!vis[y+1][x+1] ^ !vis[y+1][x-1])) {
            vis[y+1][x]=1;
            cur.pb('D');
            gen(x, y+1);
            cur.ppb();
            vis[y+1][x]=0;
        }
        else if (x+1>=7 && !vis[y+1][x+1]) {
            vis[y+1][x]=1;
            cur.pb('D');
            gen(x, y+1);
            cur.ppb();
            vis[y+1][x]=0;
        }
        else if (x-1<0 && !vis[y+1][x+1]) {
            vis[y+1][x]=1;
            cur.pb('D');
            gen(x, y+1);
            cur.ppb();
            vis[y+1][x]=0;
        }
        else if (y+1==6 && x==0 && cur.length()==47) {
            vis[y+1][x]=1;
            cur.pb('D');
            gen(x, y+1);
            cur.ppb();
            vis[y+1][x]=0;
        }
    }
    if (y-1>=0 && !vis[y-1][x]) {
        if (y-2>=0 && !vis[y-2][x]) {
            vis[y-1][x]=1;
            cur.pb('U');
            gen(x, y-1);
            cur.ppb();
            vis[y-1][x]=0;
        }
        else if (x+1<7 && x-1>=0 && !(!vis[y-1][x+1] && !vis[y-1][x-1])) {
            vis[y-1][x]=1;
            cur.pb('U');
            gen(x, y-1);
            cur.ppb();
            vis[y-1][x]=0;
        }
        else if (x+1>=7 && !vis[y-1][x-1]) {
            vis[y-1][x]=1;
            cur.pb('U');
            gen(x, y-1);
            cur.ppb();
            vis[y-1][x]=0;
        }
        else if (x-1<0 && !vis[y-1][x+1]) {
            vis[y-1][x]=1;
            cur.pb('U');
            gen(x, y-1);
            cur.ppb();
            vis[y-1][x]=0;
        }
    }
}

int main(void) {
    cin >> s;
    vis[0][0]=1;
    gen(0, 0);
    for (string c : paths) {
        int t=0;
        for (int i=0; i<48; ++i)
            if (s[i]=='?' || s[i]==c[i])
                t++;
        ans+=(t==48);
    }
    cout<<ans<<'\n';
    //cout<<paths.size()<<'\n'<<a<<'\n';
}
