#include <bits/stdc++.h>
using namespace std;

int x, y, dir=1;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    while (cin >> s) {
        char cmd=s[0];
        int v=0;
        for (int i=1; i<s.size(); ++i)
            v=v*10+(s[i]-'0');
        if (cmd=='N')
            y+=v;
        else if (cmd=='E')
            x+=v;
        else if (cmd=='S')
            y-=v;
        else if (cmd=='W')
            x-=v;
        else if (cmd=='R')
            dir=(dir+(v/90))%4;
        else if (cmd=='L')
            dir=(dir-(v/90)+4)%4;
        else {
            if (!dir)
                y+=v;
            else if (dir==1)
                x+=v;
            else if (dir==2)
                y-=v;
            else
                x-=v;
        }
    }
    cout << abs(x)+abs(y) << '\n';
}

