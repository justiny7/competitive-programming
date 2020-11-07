/*
ID: justiny7
LANG: C++
TASK: theme
*/

//new dp method - I probably need to practice more dp questions lol
#include <bits/stdc++.h>
#define fi first
#define se second
#define vec vector
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;

ifstream fin("theme.in");
ofstream fout("theme.out");

//dp array is too large - changing it to [2][5000] b/c you only have to keep track of the last 2 lines
int n, ans, dp[2][5000], notes[5000]; //dp[a][b] = length of longest matching substrings (lms) ending in a and b

int main(void) {
    fin >> n;
    if (n < 10) {
        fout << "0\n";
        return 0;
    }
    int cur, last;
    fin >> last;
    for (int i = 1; i < n; i++) {
        fin >> cur;
        notes[i-1] = cur-last;
        last = cur;
    }
    for (int i = 1; i <= n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
        for (int j = i+1; j <= n-1; j++) {
            if (notes[i-1] == notes[j-1] && j-i > dp[0][j-1]+1) { //if the two chars before the current chars are equal and the dist btwn the lms of the two before
                dp[1][j] = dp[0][j-1]+1;                        //the cur char is greater than the dist btwn the two points we're checking, then the new lms
                ans = max(ans, dp[1][j]);                         //is the current lms of the two substrings+1
            }
            else
                dp[1][j] = 0;
        }
    }
    if (ans < 4)
        ans = -1;
    fout << ans+1 << '\n';
    return 0;
}
