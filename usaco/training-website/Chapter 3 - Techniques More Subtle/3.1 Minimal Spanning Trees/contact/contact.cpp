/*
ID: justiny7
LANG: C++
TASK: contact
*/

//This was a relatively easy problem EXCEPT IT TOOK ME 6 SUBMISSIONS BECAUSE I CAN'T READ OUTPUT FILE INSTRUCTIONS but it's okay
//This program took rlyyyy long on VS but ran well within time (longest was like 0.187s) on USACO servers soo *shrug*

#include <bits/stdc++.h>

using namespace std;

ifstream fin("contact.in");
ofstream fout("contact.out");

int a, b, n;
string seq;
int patterns[13][8192]; //Length, index (in binary - ex. repetitions for pattern 1010 would be stored in [4][12])
vector<pair<int, string>> answer;

int to_dec(string s) {
	int ans = 0;
	int counter = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		if (s[i] == '1')
			ans += pow(2, counter);
		counter++;
	}
	return ans;
}

string to_bin(int len, int num) {
	string ans;
	int counter = 0;
	while (num > 0) {
		ans.append(to_string(num % 2));
		num /= 2;
		counter++;
	}
	while (ans.length() < len)
		ans.append("0");

	reverse(ans.begin(), ans.end());
	return ans;
}

bool how2Sort(pair<int, string> x, pair<int, string> y) {
	if (x.first != y.first)
		return (x.first > y.first);
	if (x.second.length() != y.second.length())
		return (x.second.length() < y.second.length());
	return (to_dec(x.second) < to_dec(y.second));
}

int main(void) {
	fin >> a >> b >> n;
	string temp;
	while (fin >> temp)
		seq.append(temp);

	for (int i = 0; i < seq.length(); i++)
		for (int j = a; j <= b; j++)
			if (i+j <= seq.length()) {
				string sub = seq.substr(i, j);
				patterns[j][to_dec(sub)]++;
			}
	
	for (int i = a; i <= b; i++)
		for (int j = 0; j < pow(2, i); j++)
			if (patterns[i][j] != 0)
				answer.push_back({ patterns[i][j], to_bin(i, j) });
	
	sort(answer.begin(), answer.end(), how2Sort);
	int curLen = -1, cnt = 0, i = 0, lineCnt;
	while (cnt < n && i < answer.size()) {
		lineCnt = 0;
		curLen = answer[i].first;
		if (curLen != 0) {
			if (i != 0)
				fout << endl;
			fout << curLen << endl << answer[i++].second;
			lineCnt++;
			cnt++;
			while (i < answer.size() && answer[i].first == curLen) {
				if (lineCnt != 0)
					fout << " ";
				fout << answer[i++].second;
				lineCnt++;
				if (lineCnt == 6 && i < answer.size()-1 && answer[i].first == curLen) {
					fout << endl;
					lineCnt = 0;
				}
			}
		}
		else
			break;
	}
	fout << endl;
	return 0;
}