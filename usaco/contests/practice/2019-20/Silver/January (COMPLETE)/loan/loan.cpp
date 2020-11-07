// USACO Silver January 2020 Problem 2

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("loan.in");
ofstream fout("loan.out");

ll n, k, m;

//Binary search for answer - once you can't get some X, you can't get bigger than X either
bool works(ll x, ll daysleft, ll milkleft) {
	//instead of going through each day, find the range in which you can give a certain amount of milk, and find how many days you can keep giving that amount
	ll y = milkleft/x;
	if (milkleft <= 0)
		return true;
	if (y <= m)
		return daysleft*m >= milkleft;
	if (y*daysleft < milkleft)
		return false;
	ll give = 1+(milkleft-x*y)/y;
	return works(x, daysleft-give, milkleft-(give*y));
}

void binSearch() {
	ll lo = 1, hi = n, biggest;
	while (lo <= hi) {
		if (lo == hi)
			break;
		ll mid = lo + (hi-lo)/2;
		if (works(mid, k, n)) {
			biggest = mid;
			lo = mid+1;
		}
		else
			hi = mid;
	}
	fout << biggest << '\n';
}

int main(void) {
	fin >> n >> k >> m;

	binSearch();

	return 0;
}