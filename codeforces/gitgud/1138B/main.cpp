#include <bits/stdc++.h>
using namespace std;

int n, oo, ll, ol, lo;
string s1, s2;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s1 >> s2;
    for (int i=0; i<n; ++i) {
        if (s1[i]=='0' && s2[i]=='0')
            ++oo;
        else if (s1[i]=='0' && s2[i]=='1')
            ++ol;
        else if (s1[i]=='1' && s2[i]=='0')
            ++lo;
        else
            ++ll;
    }
    for (int cll=0; cll<=ll; ++cll)
        for (int col=0; col<=ol; ++col) {
            int clo=ol+ll-(col+2*cll), coo=n/2-(col+clo+cll);
            if (clo<=lo && coo<=oo && clo>=0 && coo>=0) {
                for (int i=0; i<n; ++i) {
                    if (s1[i]=='0' && s2[i]=='0' && coo)
                        cout << i+1 << " ", --coo;
                    else if (s1[i]=='0' && s2[i]=='1' && col)
                        cout << i+1 << " ", --col;
                    else if (s1[i]=='1' && s2[i]=='0' && clo)
                        cout << i+1 << " ", --clo;
                    else if (s1[i]=='1' && s2[i]=='1' && cll)
                        cout << i+1 << " ", --cll;
                }
                return cout << '\n', 0;
            }
        }
    cout << "-1\n";
}

