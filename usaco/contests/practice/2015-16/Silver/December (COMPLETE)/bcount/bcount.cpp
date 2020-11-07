//USACO Silver December 2015 Problem 3
#include <bits/stdc++.h>
using namespace std;
//I guess I did this contest a while ago without knowing it 
struct cows {
    int h = 0, g = 0, j = 0;
} lineup[100001];
int n, q;

int main(void) {
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        if (i > 0)
            lineup[i] = lineup[i-1];
        if (a == 1)
            lineup[i].h++;
        else if (a == 2)
            lineup[i].g++;
        else
            lineup[i].j++;
    }
    for (int i = 0; i < q; i++) {
        int b, e;
        cin >> b >> e;
        cout << lineup[e].h-lineup[b-1].h << " " << lineup[e].g-lineup[b-1].g << " " << lineup[e].j-lineup[b-1].j << '\n';
    }
    return 0;
}
