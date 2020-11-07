/*
ID: justiny7
LANG: C++
TASK: buylow
*/

//I didn't realize I actually had to use bignums O_o

#include <bits/stdc++.h>
#define BASE 10
using namespace std;

ifstream fin("buylow.in");
ofstream fout("buylow.out");

int n, stocks[5001], decr[5001];

struct BigNum {
	int len, num[500];
	BigNum();
	void print();
} ans, ways[5001];

BigNum::BigNum() {
	len = 1;
	fill(num, num+500, 0);
}

void BigNum::print() {
	for (int i = len-1; i >= 0; i--) {
		fout << num[i];
	}
	fout << '\n';
}

BigNum add(BigNum a, BigNum b) {
	BigNum sum;
	int l = max(a.len, b.len), carry = 0;

	for (int i = 0; i < l; i++) {
		sum.num[i] = a.num[i] + b.num[i] + carry;
		carry = sum.num[i] / BASE;
		sum.num[i] %= BASE;
	}
	if (carry != 0) {
		sum.num[l] = carry;
		sum.len = l+1;
	}
	else
		sum.len = l;

	return sum;
}

int main(void) {
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> stocks[i];

	int maxsize = 1;
	for (int i = 0; i < n; i++) {
		decr[i] = 1;
		for (int j = 0; j < i; j++)
			if (stocks[j] > stocks[i] && decr[j]+1 > decr[i])
				decr[i] = decr[j]+1;
		maxsize = max(maxsize, decr[i]);

		if (decr[i] == 1)
			ways[i].num[0] = ways[i].len = 1;
		else {
			int vis = -1;
			for (int j = i-1; j >= 0; j--)
				if (decr[j]+1 == decr[i] && stocks[j] > stocks[i] && stocks[j] != vis) {
					ways[i] = add(ways[i], ways[j]);
					vis = stocks[j];
				}
		}
	}

	int vis2 = -1;
	for (int i = n-1; i >= 0; i--) {
		//cout << ways[i] << " ";
		if (decr[i] == maxsize && stocks[i] != vis2) {
			ans = add(ans, ways[i]);
			vis2 = stocks[i];
		}
	}
	/*
	cout << '\n';
	for (int i = 0; i < n; i++)
		cout << decr[i] << " ";
	cout << '\n';
	*/
	fout << maxsize << " ";
	ans.print();

	/*
	BigNum test, w, e;
	w.num[0] = 6;
	w.num[1] = 6;
	e.num[0] = 7;
	e.num[1] = 2;
	w.len = 2;
	e.len = 2;
	test = add(e, w);
	e.print();
	w.print();
	test.print();*/

	return 0;
}

/* old slow stuff

vector<set<vector<int>>> decr;

	decr.resize(n);
	vector<int> temp;
	temp.push_back(stocks[0]);
	decr[0].insert(temp);

	int maxsize = 1;
	for (int i = 1; i < n; i++) {
		int cursize = 0;
		bool pushed = false;
		for (int j = 0; j < i; j++) {
			for (auto itr = decr[j].begin(); itr != decr[j].end(); itr++) {
				temp = *itr;
				//cout << "cursize: " << cursize << '\n';
				//cout << "tempsize: " << temp.size() << '\n';
				//cout << "decrsize: " << decr[i].size() << '\n';
				if (stocks[j] > stocks[i] && temp.size() > cursize) {
					cursize = temp.size();
					decr[i].clear();
					temp.push_back(stocks[i]);
					decr[i].insert(temp);
					pushed = true;
				}
				else if (stocks[j] > stocks[i] && temp.size() == cursize) {
					temp.push_back(stocks[i]);
					decr[i].insert(temp);
					pushed = true;
				}
				else if (stocks[i] > stocks[j] && !pushed) {
					//cursize = temp.size();
					//cout << "here: " << temp.size() << '\n';
					temp.clear();
					temp.push_back(stocks[i]);
					decr[i].insert(temp);
				}
			}
		}
		maxsize = max(maxsize, cursize+1);
	}

	set<vector<int>> maxes;
	for (int i = 0; i < n; i++) {
		//cout << "ending in " << i << ":\n";
		for (auto itr = decr[i].begin(); itr != decr[i].end(); itr++) {
			temp = *itr;
			if (temp.size() == maxsize)
				maxes.insert(temp);
			//for (int p : temp)
				//cout << p << " ";
			//cout << '\n';
		}
		//cout << '\n';
	}

	fout << maxsize << " " << maxes.size() << '\n';
	*/
