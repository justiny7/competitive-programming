/*
ID: justiny7
LANG: C++
TASK: humble
*/

//Finally got around to putting this into the Visual Studio include files (referring to bits/stdc++.h)

//New version w/ sets
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("humble.in");
ofstream fout("humble.out");

int k, n, primes[101];
set<ll> humble;

int main(void) {
	fin >> k >> n;
	for (int i = 0; i < k; i++)
		fin >> primes[i];
	sort(primes, primes + k);
	
	humble.insert(1); //Base multiplier
	ll cur;
	for (int i = 1; i <= n; i++) { //Go through the n humble numbers
		cur = *humble.begin();
		humble.erase(humble.begin());
		for (int j = 0; j < k; j++) {
			if (humble.size() <= n)
				humble.insert(cur*primes[j]);
			else if (cur*primes[j] < *(--humble.end())) { //to keep within memory bounds - you only need to keep track of up to n potential humble numbers at once
				humble.insert(cur*primes[j]);
				humble.erase(--humble.end());
			}
		}
	}

	fout << *humble.begin() << '\n';
	
	return 0;
}