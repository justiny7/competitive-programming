//USACO Silver February 2018 Problem 2

#include <bits/stdc++.h>
using namespace std;

ifstream fin("snowboots.in");
ofstream fout("snowboots.out");

int n, b, d[251], cb, bd[251], bs[251]; //depth, current boot, boot depth, boot step
bool dp[251];

int main(void) {
    fin >> n >> b;
    for (int i = 0; i < n; i++)
        fin >> d[i];
    for (int i = 0; i < b; i++)
        fin >> bd[i] >> bs[i];
    dp[0] = true;
    for (; cb < b; cb++) {
        for (int i = 0; i < n; i++)
            if (dp[i] && bd[cb] >= d[i])
                for (int j = 1; j <= bs[cb]; j++)
                    if (!dp[min(i+j, n-1)] && d[min(i+j, n-1)] <= bd[cb]) //don't wanna go over array bounds (to avoid accessing memory out of bounds)
                        dp[min(i+j, n-1)] = true;
        if (dp[n-1])
            break;
    }
    fout << cb << '\n';
    return 0;
}
