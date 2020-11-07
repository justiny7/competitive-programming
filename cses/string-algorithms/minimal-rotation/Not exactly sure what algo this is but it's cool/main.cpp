//Definitely not copied from someone else xd
//At least I learned how it works
#include <bits/stdc++.h>
using namespace std;

string s;
int n, x;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s, n=s.size(), s+=s;
    for (int i=0, j=0, k=1; i<n;) {
        x=j=i, k=i+1;
        while (k<2*n && s[j]<=s[k]) {
            if (s[j]==s[k++])
                ++j;
            else
                j=i;
        }
        while (i<=j)
            i+=k-j;
    }
    cout << s.substr(x, n) << '\n';
}

