/*
ID: justiny7
LANG: C++
TASK: fence6
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("fence6.in");
ofstream fout("fence6.out");

struct Fence {
	int len;
	vector<int> leftFences, rightFences;
};

int n, smallest = 1e9;
vector<Fence> fences;
vector<int> already;

void print() {
	for (int i = 1; i <= n; i++) {
		cout << "ID: " << i << "\nLen: " << fences[i].len;
		cout << "\nLeft neigbors:\n";
		for (int j = 0; j < fences[i].leftFences.size(); j++)
			cout << fences[i].leftFences[j] << " ";
		cout << "\nRight neighbors:\n";
		for (int j = 0; j < fences[i].rightFences.size(); j++)
			cout << fences[i].rightFences[j] << " ";
		cout << '\n';
	}
}

bool inLeft(int num, int index) {
	for (int i = 0; i < fences[index].leftFences.size(); i++)
		if (fences[index].leftFences[i] == num)
			return true;
	return false;
}

bool inRight(int num, int index) {
	for (int i = 0; i < fences[index].rightFences.size(); i++)
		if (fences[index].rightFences[i] == num)
			return true;
	return false;
}


string to_hex(int x) {
	string ans = "";
	while (x > 0) {
		int rem = x%16;

		if (rem < 10)
			ans.push_back(rem + 48);
		else
			ans.push_back(rem + 55);

		x /= 16;
	}
	while (ans.length() < 2)
		ans.push_back('0');
	reverse(ans.begin(), ans.end());
	return ans;
}

int to_dec(string x) {
	int ans = 0, base = 1;
	if (x.length() < 2)
		x.insert(0, "0");
	for (int i = 1; i >= 0; i--) {
		if (x[i] >= '0' && x[i] <= '9') {
			ans += (x[i] - 48)*base;
		}
		else
			ans += (x[i] - 55)*base;
		base *= 16;
	}
	return ans;
}

bool inString(string str, int x) {
	for (int i = 0; i < str.length(); i+=2)
		if (to_dec(str.substr(i, 2)) == x)
			return true;
	return false;
}

int main(void) {
	fin >> n;
	fences.resize(n+1);
	for (int i = 0; i < n; i++) {
		int id;
		fin >> id;
		int a, b;
		fin >> fences[id].len >> a >> b;
		fences[id].leftFences.resize(a);
		fences[id].rightFences.resize(b);
		for (int j = 0; j < a; j++)
			fin >> fences[id].leftFences[j];
		for (int j = 0; j < b; j++)
			fin >> fences[id].rightFences[j];
	}

	//print();

	
	for (int i = 1; i <= n; i++) {
		sort(already.begin(), already.end());
		if (binary_search(already.begin(), already.end(), i))
			continue;
		queue<pair<string, int>> q;
		q.push({to_hex(i), fences[i].len});
		int smallestLen = 1e9, smallestPer = 1e9;
		string candidate;
		while (!q.empty()) {
			string path = q.front().first;
			int curLen = q.front().second;
			q.pop();

			if (path.length() > smallestLen) {
				//cout << "---\n" << candidate << '\n' << smallestPer << "\n---\n\n";
				for (int i = 0; i < candidate.length(); i+=2)
					already.push_back(to_dec(candidate.substr(i, 2)));
				break;
			}
			
			int last, last2;
			if (path.length() > 2)
				last2 = to_dec(path.substr(path.length()-4, 2));
			else
				last2 = to_dec(path.substr(0, 1));
			last = to_dec(path.substr(path.length()-2, 2));
			//cout << "last: " << last << '\n';
			//cout << "path: " << path << '\n';
			bool left = true;
			if (inLeft(last2, last))
				left = false;

			//cout << "smallest length: " << smallestLen << '\n';

			if (left) {
				//cout << "left\n";
				for (int p = 0; p < fences[last].leftFences.size(); p++) {
					int num = fences[last].leftFences[p];
					//cout << "num: " << num << '\n';
					if (inRight(num, i)) {
						//cout << "INRIGHT: " << path + to_hex(num) << '\n';
						if (path.length() <= smallestLen && curLen + fences[num].len < smallestPer) {
							smallestLen = path.length();
							smallestPer = curLen + fences[num].len;
							candidate = path + to_hex(num);
							//cout << "done\n";
						}
					}
					else if (!inString(path, num) && curLen + fences[num].len < smallest) {
						//cout << "newpath: " << path + to_hex(num) << '\n';
						q.push({path + to_hex(num), curLen + fences[num].len});
					}
				}
			}
			else {
				//cout << "right\n";
				for (int p = 0; p < fences[last].rightFences.size(); p++) {
					int num = fences[last].rightFences[p];
					if (inRight(num, i)) {
						//cout << "INRIGHT: " << path + to_hex(num) << '\n';
						if (path.length() <= smallestLen && curLen + fences[num].len < smallestPer) {
							smallestLen = path.length() + 1;
							smallestPer = fences[num].len + curLen;
							candidate = path + to_hex(num);
							//cout << "done\n";
						}
					}
					else if (!inString(path, num) && curLen + fences[num].len < smallest)
						q.push({path + to_hex(num), curLen + fences[num].len});
				}
			}
			//cout << '\n';

		}
		smallest = min(smallest, smallestPer);

		//break;
	}

	fout << smallest << '\n';

	return 0;
}