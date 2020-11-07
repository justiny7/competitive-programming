#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n, pcnt=1, ncnt;
vector<bool> ord;
vector<int> give;
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> s && s!="=") {
        if (s=="+")
            ++pcnt, ord.pb(1);
        else if (s=="-")
            ++ncnt, ord.pb(0);
    }
    cin >> n;
    if (n>n*pcnt-ncnt || n<pcnt-n*ncnt)
        return cout << "Impossible\n", 0;
    cout << "Possible\n";
    int cur=0;
    for (int i=0; i<ord.size(); ++i) {
        int s=(!i || (i && ord[i-1]))?(--pcnt, 1):(--ncnt, -1);
        for (int j=1; j<=n; ++j)
            if (n-cur>=pcnt-n*ncnt+j*s && n-cur<=n*pcnt-ncnt+j*s) {
                cout << j << " " << (ord[i]?"+":"-") << " ", cur+=j*s;
                break;
            }
    }
    cout << abs(cur-n) << " = " << n << '\n';
}

