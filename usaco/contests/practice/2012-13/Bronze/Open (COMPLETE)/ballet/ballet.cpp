#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using pii=pair<int, int>;

int n, dir, mxr=1, mxl, mxu=1, mxb, dy[]={1,0,-1,0}, dx[]={0,1,0,-1};
pii pos[4]={{0, 0}, {1, 0}, {0, 1}, {1, 1}};
map<string, int> mp;

bool check() {
    for (int i=0; i<4; ++i)
        for (int j=i+1; j<4; ++j)
            if (pos[i]==pos[j])
                return 0;
    return 1;
}
void upd() {
    for (int i=0; i<4; ++i) {
        mxr=max(mxr, pos[i].x);
        mxl=min(mxl, pos[i].x);
        mxu=max(mxu, pos[i].y);
        mxb=min(mxb, pos[i].y);
    }
}

int main() {
    ifstream cin("ballet.in");
    ofstream cout("ballet.out");
    cin >> n;
    mp["RL"]=0, mp["RR"]=1, mp["FL"]=2, mp["FR"]=3;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        int f=mp[s.substr(0, 2)];
        char c=s[2];
        if (c^'P') {
            int ind=dir;
            if (c=='R')
                ++ind;
            else if (c=='B')
                ind+=2;
            else if (c=='L')
                ind+=3;
            ind%=4;
            pos[f].x+=dx[ind], pos[f].y+=dy[ind];
        }
        else {
            int a=pos[f].x, b=pos[f].y;
            for (int i=0; i<4; ++i) {
                int tx=pos[i].x, ty=pos[i].y;
                pos[i]={ty-b+a, a+b-tx};
            }
            dir=(dir+1)%4;
        }
        if (!check())
            return cout << "-1\n", 0;
        upd();
    }
    cout << (mxr-mxl+1)*(mxu-mxb+1) << '\n';
}

