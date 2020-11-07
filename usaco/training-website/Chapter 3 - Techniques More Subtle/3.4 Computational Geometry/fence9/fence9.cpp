/*
ID: justiny7
LANG: C++
TASK: fence9
*/

/*
	IDEA: 2 scenarios - p < n, p >= n
	p < n: cycle through each x from 1 - n-1, do floor(y1(x)) - floor(y2(x))
	p >= n: cycle through each x form 1 - p-1, just do floor(y1(x)) when x <= n and floor(y2(x)) when x > n
*/

//In the end, a really messy solution (prob could've been easier if I used doubles instead of num/den) but it worked so yay

#include <bits/stdc++.h>
#define slope m2/slopeden
#define yint yintnum/slopeden
using namespace std;

ifstream fin("fence9.in");
ofstream fout("fence9.out");

int n, n1, m, m2, p, slopeden, yintnum;

//eq: y = m/n*x
int y1(int x) {
	if (x%n == 0)
		return (int)((double)m/n * x) - 1;
	return (int) ((double)m/n * x);
}

int y2 (int x, bool lower) {
	if ((x+yintnum)%slopeden == 0 && !lower)
		return (int)((double)slope * x + (double)yint) - 1;
	return (int)((double)slope * x + (double)yint);
}


void simplify() {
	int GCD1 = __gcd(m, n);
	if (GCD1 != 0) {
		m /= GCD1;
		n /= GCD1;
	}

	//cout << m << "/" << n << '\n';

	int GCD2 = __gcd(m2, slopeden);
	GCD2 = __gcd(yintnum, GCD2);
	if (GCD2 != 0) {
		m2 /= GCD2;
		slopeden /= GCD2;
		yintnum /= GCD2;
	}

	//cout << m2 << "/" << slopeden << '\n';
	//cout << yintnum << "/" << slopeden << '\n';
}

int main(void) {
	fin >> n >> m >> p;
	n1 = n;
	m2 = m;
	slopeden = n-p;
	yintnum = m*(slopeden-n);

	simplify();

	int ans = 0;
	if (n1 == 0 && p != 0) {
		for (int i = 1; i < p; i++) {
			//cout << y2(i) << '\n';
			ans += y2(i, false);
		}
	}
	else if (n1 == 0 && p == 0) {
		fout << "0\n";
		return 0;
	}
	else if (p < n1) {
		for (int i = 1; i < n1; i++) {
			//cout << y1(i) << " - " << max(y2(i, true), 0) << '\n';
			ans += y1(i) - max(y2(i, true), 0);
		}
	}
	else if (p > n1) {
		for (int i = 1; i < p; i++) {
			if (i < n1) {
				//cout << y1(i) << '\n';
				ans += y1(i);
			}
			else {
				//cout << y2(i) << '\n';
				ans += y2(i, false);
			}
		}
	}
	else {
		for (int i = 1; i < n1; i++) {
			//cout << y1(i) << '\n';
			ans += y1(i);
		}
	}

	fout << ans << '\n';

	return 0;
}