/*
ID: justiny7
LANG: C++
TASK: fact4
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("fact4.in");
ofstream fout("fact4.out");

long long ans[4221], num[4221];
int n;

int main(void) {
	fin >> n;
	ans[1] = 1;
	num[1] = 1;
	for (int i = 2; i <= n; i++) {
		num[i] = (i * num[i - 1]);
		while (num[i] % 10 == 0)
			num[i] /= 10;
		num[i] %= 1000000000;
		ans[i] = num[i];

		while (ans[i] % 10 == 0)
			ans[i] /= 10;
		ans[i] %= 10;

		//cout << ans[i] << endl;
	}

	fout << ans[n] << endl;

	return 0;
}