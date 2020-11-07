//Yay got it second try after not reading something
#include <bits/stdc++.h>
using namespace std;

const int mxN=251;
int n, b, a[mxN], d[mxN], s[mxN];
bool dp[mxN];

int main() {
    ifstream cin("snowboots.in");
    ofstream cout("snowboots.out");
    cin >> n >> b;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<b; ++i)
        cin >> d[i] >> s[i];
    dp[0]=1;
    for (int i=0; i<b; ++i) {
        for (int j=0; j<n; ++j)
            if (dp[j] && a[j]<=d[i])
                for (int k=0; k<=s[i]; ++k)
                    if (j+k<n && a[j+k]<=d[i])
                        dp[j+k]=1;
        if (dp[n-1]) {
            cout << i << '\n';
            break;
        }
    }
}

