/*
ID: justiny7
LANG: C++
TASK: barn1
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("barn1.in");
ofstream fout("barn1.out");

int m, s, c; //The program doesn't even use s at all lol
vector<int> cows, gaps;

int main(void) {
    fin >> m >> s >> c;
    if (m >= c) {
        fout << c << '\n';
        return 0;
    }
    cows.resize(c);
    for (int i = 0; i < c; i++)
        fin >> cows[i];
    sort(cows.begin(), cows.end());
    for (int i = 1; i < c; i++)
        gaps.push_back(cows[i]-cows[i-1]-1);
    sort(gaps.begin(), gaps.end(), greater<int>());
    int sub = 0;
    for (int i = 0; i < m-1; i++)
        sub += gaps[i];

    fout << (cows[c-1]-cows[0]+1)-sub << '\n';

    return 0;
}
