/*
ID: justiny7
LANG: C++
TASK: kimbits
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");

long long N, L, I;
//time to try dp... -_-
long long sizes[32][32]; // sizes[a][b] = size of set of a bits and up to b 1s

/*
After like 2 hrs of thinking... -_-
Sooo if the I'th number is greater than the size of set[N-1][L] (1 smaller length but same # of ones) then you know that it has
to be a 1 because otherwise it would be able to fit within that range
Then, we subtract set[N-1][L] from I to get the next number to check, and decrease the Length by 1
Otherwise, we just add a 0, leave I alone, and decrease the length by 1
*/

void recPrint() {
	if (N == 0)
		return;

	long long curSize = sizes[N-1][L];
	if (I >= curSize) {
		fout << 1;
		N--, L--, I -= curSize;
	}
	else {
		fout << 0;
		N--;
	}
	recPrint();
}

int main(void) {
	fin >> N >> L >> I;
	I--;

	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 32; j++) {
			if (i == 0 || j == 0)
				sizes[i][j] = 1; //only one way to make set with size 0/only 0 bits
			else
				sizes[i][j] = sizes[i-1][j] + sizes[i-1][j-1]; //So sizes[i-1][j] = size of set w/ length i-1 but same # of ones (so adding a 0)
		}													   //And the other one is size of set w/ length i-1 and j-1 ones (so adding 1! big brain)
	
	recPrint();
	fout << endl;
	
	return 0;
}

/* Old functions..

int cnt1s(int a) {
	int ans;
	for (ans = 0; a > 0; a /= 2)
		if (a % 2 == 1)
			ans++;
	return ans;
}

string to_bin(int a, int length) {
	string ans = "";
	while (a > 0) {
		ans.append(to_string(a % 2));
		a /= 2;
	}
	while (ans.size() < length)
		ans.append("0");
	reverse(ans.begin(), ans.end());
	return ans;
}

long long Choose(int a, int b) {
	int ans = a;
	if (2 * b > a)
		b = a - b;
	if (b == 0)
		return 1;
	for (int i = 2; i <= b; i++) {
		ans *= (a - i + 1);
		ans /= i;
	}

	return ans;
}

*/

/* random counting way that only worked for a few test cases but had exceptions I forgot to consider
	I--;
	int len = binCnt(I) - 1;

	for (int i = L + 1; i < len; i++) {
		//cout << len << " " << i << endl;
		int curr = Choose(len, i);
		I += curr;
	}

	//cout << I << endl;
	fout << to_bin(I, N) << endl;
	

*/

/* Some test code I knew was too slow (but still got 11/13!)

int binCnt(int a) {
	int ans;
	for (ans = 0; a > 0; a /= 2, ans++);
	return ans;
}

	if (N != L) {
		int i, counter;
		for (i = 0, counter = 0; counter < I; i++)
			if (cnt1s(i) <= L)
				counter++;
		fout << to_bin(i - 1, N) << endl;
		return 0;
	}

	fout << to_bin(I-1, N) << endl;



*/