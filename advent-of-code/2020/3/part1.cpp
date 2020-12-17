#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test.txt", "r", stdin);
    vector<string> v;
    {
        string s;
        while (cin >> s)
            v.push_back(s);
    }
    int p=0, c=0;
    for (int i=0; i<v.size(); ++i)
        c+=(v[i][p]=='#'), p=(p+3)%v[i].size();
    cout << c << '\n';
}

