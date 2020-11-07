//USACO Silver December 2015 Problem 2
#include <bits/stdc++.h>
using namespace std;
//I also did this one before
int n, ans;
vector<int> bessie, elsie;
bool taken[100001];

int main(void) {
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> n;
    bessie.resize(n);
    elsie.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> elsie[i];
        taken[elsie[i]] = true;
    }
    int ind = 0;
    for (int i = 1; i <= 2*n; i++) {
        if (!taken[i]) {
            bessie[ind] = i;
            ind++;
        }
        if (ind == n)
            break;
    }
    int e = 0;
    sort(bessie.begin(), bessie.end());
    sort(elsie.begin(), elsie.end());
    for (int i = 0; i < n; i++) {
        if (bessie[i] > elsie[e])
            e++;
    }
    cout << e << '\n';
}

