#include <bits/stdc++.h>
using namespace std;
using ll=long long;

vector<string> v;

ll f(int x, int y) {
    ll ret=0;
    for (int i=0, p=0; i<v.size(); i+=y)
        ret+=(v[i][p]=='#'), p=(p+x)%v[i].size();
    return ret;
}

int main() {
    freopen("test.txt", "r", stdin);
    {
        string s;
        while (cin >> s)
            v.push_back(s);
    }
    ll ans=1;
    ans*=f(1, 1);
    ans*=f(3, 1);
    ans*=f(5, 1);
    ans*=f(7, 1);
    ans*=f(1, 2);
    cout << ans << '\n';
}


