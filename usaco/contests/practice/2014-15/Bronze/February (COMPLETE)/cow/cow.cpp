#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("cow.in");
ofstream fout("cow.out");

const int mxN=1e5+1;
int n;
ll c[mxN], o[mxN], ans;
string s;

int main(void) {
    fin >> n >> s;
    for (int i=0; i<n; ++i) {
        c[i]=(s[i]=='C');
        if (i)
            c[i]+=c[i-1];
        if (s[i]=='O')
            o[i]=c[i];
        if (i)
            o[i]+=o[i-1];
        if (s[i]=='W')
            ans+=o[i];
    }
    fout << ans << '\n';
}
