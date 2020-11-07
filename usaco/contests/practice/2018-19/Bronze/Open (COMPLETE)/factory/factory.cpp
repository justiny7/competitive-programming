//Factory - USACO US Open 2018 Bronze Problem #2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("factory.in");
ofstream fout("factory.out");

int n, in[101], out[101], ans = -1;

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        out[a]++;
        in[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0 && in[i] > 0 && ans == -1)
            ans = i;
        else if (out[i] == 0 && in[i] > 0 && ans != -1) {
            fout << "-1\n";
            return 0;
        }
    }
    fout << ans << '\n';
    return 0;
}
