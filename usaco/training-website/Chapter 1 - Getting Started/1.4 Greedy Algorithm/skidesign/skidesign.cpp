/*
ID: justiny7
LANG: C++
TASK: skidesign
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("skidesign.in");
ofstream fout("skidesign.out");

int n, ans = 1e9;
vector<int> hills;

int main(void) {
    fin >> n;
    hills.resize(n);
    for (int i = 0; i < n; i++)
        fin >> hills[i];

    for (int a = 0; a <= 83; a++) {
        int curcost = 0;
        for (int i = 0; i < n; i++) {
            if (hills[i] < a)
                curcost += (a-hills[i])*(a-hills[i]);
            else if (hills[i] > a+17)
                curcost += (hills[i]-17-a)*(hills[i]-17-a);
        }
        ans = min(ans, curcost);
    }
    fout << ans << '\n';
    return 0;
}
