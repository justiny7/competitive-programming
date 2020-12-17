#include <bits/stdc++.h>
using namespace std;

int x, y, wx=10, wy=1;

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    while (cin >> s) {
        char cmd=s[0];
        int v=0;
        for (int i=1; i<s.size(); ++i)
            v=v*10+(s[i]-'0');
        if (cmd=='N')
            wy+=v;
        else if (cmd=='E')
            wx+=v;
        else if (cmd=='S')
            wy-=v;
        else if (cmd=='W')
            wx-=v;
        else if (cmd=='R')
            for (int i=0; i<v/90; ++i)
                swap(wx, wy), wy*=-1;
        else if (cmd=='L')
            for (int i=0; i<v/90; ++i)
                swap(wx, wy), wx*=-1;
        else
            x+=wx*v, y+=wy*v;
    }
    cout << abs(x)+abs(y) << '\n';
}

