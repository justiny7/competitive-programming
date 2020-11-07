//USACO Bronze US Open 2015 Problem 2
#include <bits/stdc++.h>
using namespace std;
//I like this problem - very cool
ifstream fin("geteven.in");
ofstream fout("geteven.out");

int n, numodd=1, numtot=1; //idea: #even=#tot-#odds, it's odd if all three expressions are odd
map<char, vector<int>> nums;

int findodd(int w) {
    int cnt=0;
    if (w==1) { //word 1 = B+I+2(S+E), so you only have to check if B+I is odd (2(S+E) is always even)
        for (int i : nums['B'])
            for (int j : nums['I'])
                if ((i+j)&1)
                    cnt++;
    }
    if (w==2) {
        for (int i : nums['G']) //word 2 = G+O+E+S - just check if entire word is odd
            for (int j : nums['O'])
                for (int k : nums['E'])
                    for (int l : nums['S'])
                        if ((i+j+k+l)&1)
                            cnt++;
    }
    if (w==3) {
        for (int i : nums['M']) //word 3 = M+2O, 2O is always even so check if M is odd
            if (i&1)
                cnt++;
    }
    return cnt;
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        char c;
        int a;
        fin >> c >> a;
        nums[c].push_back(a);
    }
    for (int i=1; i<=3; ++i)
        numodd*=findodd(i);
    for (auto p : nums)
        numtot*=p.second.size();
    fout << numtot-numodd << '\n';
}
