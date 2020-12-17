#include <bits/stdc++.h>
using namespace std;

void process(int &a, int &b, string &s) {
    a=b=0;
    int i=0;
    for (; s[i]^','; ++i)
        a=a*10+(s[i]-'0');
    for (++i; i<s.size(); ++i)
        b=b*10+(s[i]-'0');
}

const int mxN=1e3;
int board[mxN][mxN];

int main() {
    freopen("test.txt", "r", stdin);
    //brute force before moving onto faster things
    string s;
    while (getline(cin, s)) {
        if (s.empty())
            break;
        stringstream ss(s);
        string s1, s2, garbage, c1, c2;
        ss >> s1;
        if (s1=="turn")
            ss >> s2;
        ss >> c1 >> garbage >> c2;
        int x1, x2, y1, y2;
        process(x1, y1, c1);
        process(x2, y2, c2);
        for (int i=x1; i<=x2; ++i)
            for (int j=y1; j<=y2; ++j) {
                if (s1=="toggle")
                    board[i][j]+=2;
                else if (s2=="on")
                    ++board[i][j];
                else
                    board[i][j]=max(0, board[i][j]-1);
            }
    }
    int ans=0;
    for (int i=0; i<mxN; ++i)
        for (int j=0; j<mxN; ++j)
            ans+=(board[i][j]);
    cout << ans << '\n';
}

