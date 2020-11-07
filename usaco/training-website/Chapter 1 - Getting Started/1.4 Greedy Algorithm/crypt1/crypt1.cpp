/*
ID: justiny7
LANG: C++
TASK: crypt1
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");

int n, ans;
vector<int> digs;

bool works(int x) {
    string s = to_string(x);
    int counter = 0;
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < n; j++)
            if (s[i]-'0' == digs[j]) {
                counter++;
                break;
            }
    return (counter == s.length());
}

int main(void) {
    fin >> n;
    digs.resize(n);
    for (int i = 0; i < n; i++)
        fin >> digs[i];

    for (int a = 0; a < n; a++) {
        int abc, de;
        for (int b = 0; b < n; b++)
            for (int c = 0; c < n; c++)
                for (int d = 0; d < n; d++)
                    for (int e = 0; e < n; e++) {
                        abc = 100*digs[a]+10*digs[b]+digs[c];
                        de = 10*digs[d]+digs[e];
                        if (abc*de < 1e4 && works(abc*de)
                            && (abc*digs[d] < 1e3 && works(abc*digs[d]))
                            && (abc*digs[e] < 1e3 && works(abc*digs[e])))
                            ans++;                            
                    }
    }
    fout << ans << '\n';
    return 0;
}
