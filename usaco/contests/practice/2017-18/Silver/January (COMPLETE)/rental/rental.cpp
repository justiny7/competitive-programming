//USACO Silver January 2018 Problem 2

//Simple greedy problem that took me too long to debug
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ifstream fin("rental.in");
ofstream fout("rental.out");

ll n, m, r, cows[100001], rentals[100001], curprice, ans, curcow, cowsrented;
map<ll, ll, greater<ll>> offmap;
vector<pll> offers;

int main(void) {
    fin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        fin >> cows[i];
    sort(cows, cows+n);
    for (int i = 0; i < m; i++) {
        int a, b;
        fin >> a >> b;
        offmap[b] += a;
    }
    for (pll p : offmap)
        offers.push_back(p);
    for (int i = 0; i < r; i++)
        fin >> rentals[i];
    sort(rentals, rentals+r);
    for (int i = r-1; i >= 0; i--)
        if (curcow < n) {
            curprice += rentals[i];
            curcow++;
        }
    cowsrented = curcow;
    int offind = 0;
    while (curcow < n && offind < offers.size())
        for (; offind < offers.size(); offind++) {
            if (cows[curcow] <= offers[offind].se) {
                curprice += offers[offind].fi*cows[curcow];
                offers[offind].se -= cows[curcow];
                curcow++;
                break;
            }
            else {
                curprice += offers[offind].fi*offers[offind].se;
                cows[curcow] -= offers[offind].se;
                offers[offind].se = 0;
            }
        }
    int rentind = r-cowsrented;
    ans = curprice;
    while (1) {
        curprice -= rentals[rentind];
        //cout << "getting rid of rental price " << rentals[rentind] << '\n';
        //cout << "now our price is " << curprice << '\n';
        rentind++;
        cowsrented--;
        //cout << "the current cow is " << cowsrented << " and it has a cap of " << cows[cowsrented] << '\n';
        //cout << "our current offind is " << offind << '\n';
        for (; offind < offers.size(); offind++) {
            if (cows[cowsrented] <= offers[offind].se) {
                curprice += offers[offind].fi*cows[cowsrented];
                offers[offind].se -= cows[cowsrented];
                break;
            }
            else {
                curprice += offers[offind].fi*offers[offind].se;
                cows[cowsrented] -= offers[offind].se;
                offers[offind].se = 0;
            }
        }
        //cout << "now offind is " << offind << '\n';
        //cout << "our current price is " << curprice << '\n';
        ans = max(curprice, ans);
        if (offind == offers.size() || cowsrented == 0)
            break;
    }
    fout << ans << '\n';
    return 0;
}
