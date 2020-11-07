#include <bits/stdc++.h>
using namespace std;

int b[8][8], ans;

void place(int y, int x) {
    for (int i=0; i<8; ++i) {
        b[y][i]++;
        b[i][x]++;
        
    }
    for (int j=-8; j<=8; ++j) {
        if (y+j>=0 && y+j<8 && x+j>=0 && x+j<8)
            b[y+j][x+j]++;
        if (y+j>=0 && y+j<8 && x-j>=0 && x-j<8)
            b[y+j][x-j]++;
    }
    b[y][x]-=3;
}

void rem(int y, int x) {
    for (int i=0; i<8; ++i) {
        b[y][i]--;
        b[i][x]--;
        
    }
    for (int j=-8; j<=8; ++j) {
        if (y+j>=0 && y+j<8 && x+j>=0 && x+j<8)
            b[y+j][x+j]--;
        if (y+j>=0 && y+j<8 && x-j>=0 && x-j<8)
            b[y+j][x-j]--;
    }
    b[y][x]+=3;
}

void solve(int cur) {
    if (cur==8) {
        ans++;
        return;
    }
    for (int i=0; i<8; i++)
        if (b[cur][i]==0) {
            place(cur, i);
            solve(cur+1);
            rem(cur, i);
        }
}

int main(void) {
    for (int i=0; i<8; ++i)
        for (int j=0; j<8; ++j) {
            char c;
            cin >> c;
            b[i][j]=(c=='.')?0:1;
        }
    solve(0);
    cout << ans << '\n';
}
