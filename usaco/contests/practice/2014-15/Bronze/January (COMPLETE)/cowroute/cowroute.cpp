#include <bits/stdc++.h>
using namespace std;

ifstream fin("cowroute.in");
ofstream fout("cowroute.out");

int a, b, n, ans=INT_MAX;

int main(void) {
    fin >> a >> b >> n;
    for (int i=0; i<n; ++i) {
        int c, k;
        fin >> c >> k;
        bool f1=0, f2=0;
        while (k--) {
            int p; fin >> p;
            if (a==p)
                f1=1;
            if (b==p && f1)
                f2=1;
        }
        if (f1 && f2)
            ans=min(ans, c);
    }
    if (ans==INT_MAX)
        fout << "-1\n";
    else
        fout << ans << '\n';
}
