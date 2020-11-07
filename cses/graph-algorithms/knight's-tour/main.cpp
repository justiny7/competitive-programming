#include <bits/stdc++.h>
using namespace std;

int x, y, b[8][8], kx[8]={1, 2, 2, 1, -1, -2, -2, -1}, ky[8]={2, 1, -1, -2, -2, -1, 1, 2};

int deg(int cx, int cy) {
    int cnt=8;
    for (int i=0; i<8; i++) {
        int nx=cx+kx[i], ny=cy+ky[i];
        if (nx<0 || nx>=8 || ny<0 || ny>=8 || b[ny][nx]>0)
            cnt--;
    }
    return cnt;
}

void solve(int cx, int cy) {
    //cout << cy << " " << cx << " " << b[cy][cx] << '\n';
    for (int cur=1; cur<=64; cur++) {
        b[cy][cx]=cur;
        int best, mind=9; //best next move, minimum degree
        for (int i=0; i<8; i++) {
            int ny=cy+ky[i], nx=cx+kx[i];
            if (nx>=0 && nx<8 && ny>=0 && ny<8 && b[ny][nx]==0)
                if (deg(nx, ny)<mind) {
                    mind=deg(nx, ny);
                    best=i;
                }
        }
        cy+=ky[best], cx+=kx[best];
    }
}

int main(void) {
    cin >> x >> y;
    x--, y--;
    solve(x, y);
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (j==0)
                cout << b[i][j];
            else
                cout << " " << b[i][j];
        }
        cout << '\n';
    }
}
