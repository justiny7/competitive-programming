#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
string s;

char solve() {
    int a=count(s.begin(), s.end(), 'A'),
        b=count(s.begin(), s.end(), 'B');
    if (max(a, b)==min(a, b)+1)
        return 'Y';
    else
        return 'N';
}

int main() {
    int t; fin >> t;
    for (int tt=1; tt<=t; ++tt) {
        fin >> n >> s;
        fout << "Case #" << tt << ": " << solve() << '\n';
    }
}
