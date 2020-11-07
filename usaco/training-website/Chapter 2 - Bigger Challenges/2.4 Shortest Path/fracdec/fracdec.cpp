/*
ID: justiny7
LANG: C++
TASK: fracdec
*/

//I was so dumb in this question - instead of recording where the "(" should've went, I tried counting backwards
//So instead of recording where each subsum was, I +1ed all the ones that were >0 and counted backward
//Anyways, took me like 8 tries and 1 shower to get it but I did it in the end - chapter 3 here we come!!


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");

int n, d;
string ans;
int subsums[999999];

int main(void) {
	fin >> n >> d;

	if (n >= d) {
		ans.append(to_string((int)(n / d)) + ".");
		n %= d;
	}
	else
		ans.append("0.");

	if (n == 0) {
		ans.append("0");
		fout << ans << endl;
		return 0;
	}

	while (1) {
		if (subsums[n] > 0) {
			ans.insert(subsums[n], "(");
			ans.append(")");
			break;
		}

		subsums[n] = ans.size();
		n *= 10;

		if (d > n)
			ans.append("0");
		else if (n % d == 0) {
			ans.append(to_string(n / d));
			break;
		}
		else {
			int temp = n / d;
			ans.append(to_string(temp));
			n -= temp * d;
		}
		//cout << ans << endl;
	}
	for (int i = 0; i < ans.length(); i++) {
		fout << ans[i];
		if (i % 76 == 75)
			fout << endl;
	}

	if (ans.length() % 76 != 0 || ans.length() < 76)
		fout << endl;

	return 0;
}