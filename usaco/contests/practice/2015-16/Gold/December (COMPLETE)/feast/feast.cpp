#include <bits/stdc++.h>
using namespace std;
//I way overthought this but I got it on the second try
ifstream fin("feast.in");
ofstream fout("feast.out");

const int mxT=5e6+1;
int t, a, b;
bitset<mxT> pos;

int main(void) {
    fin >> t >> a >> b;
    pos[0]=1;
    for (int i=0; i<=t; ++i)
        if (pos[i])
            pos[i+a]=pos[i+b]=pos[i/2]=1;
    for (int i=0; i<=t; ++i)
        if (pos[i])
            pos[i+a]=pos[i+b]=1;
    for (int i=t; i>=0; --i)
        if (pos[i]) {
            fout << i << '\n';
            break;
        }
}
