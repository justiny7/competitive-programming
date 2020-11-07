/*
ID: justiny7
LANG: C++11
TASK: prefix
*/

/*
	Probably the most complicated and confusing code I have ever written in my life - I had no idea what was going
	on most of the time.

	I'm surprised doing a binary search every single match ran in time ;-;

	But point is, it worked, so I'm happy c:
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

ifstream fin("prefix.in");
ofstream fout("prefix.out");

vector<pair<int, string>> primitives; //length, then primitive string

int Max = -1;

int main(void) {
	string temp;
	string S = "";
	do {
		fin >> temp;
		primitives.push_back({ temp.length(), temp });
	} while (temp != ".");
	primitives.pop_back();
	sort(primitives.begin(), primitives.end());

	//for (int i = 0; i < primitives.size(); i++)
	//	cout << primitives[i].first << " " << primitives[i].second << endl;
	

	while (fin >> temp)
		S.append(temp);
	//cout << S << endl;

	bool pushed;
	bool done = false;
	bool first = true;
	int curMax = 0;
	int index = primitives.size();
	vector<int> cycle;
	stack <pair<int, int>> stk;
	while (!done) {
		pushed = false;
		for (int i = index-1; i >= 0; i--) {
			string substring = S.substr(curMax, primitives[i].first);
			if (primitives[i].second == substring) {
				stk.push({ curMax, i });
				curMax += primitives[i].first;
				if (binary_search(cycle.begin(), cycle.end(), curMax))
					done = true;
				else
					cycle.push_back(curMax);
				pushed = true;
				break;
			}
		}
		if (!pushed && !stk.empty()) {
			curMax = stk.top().first;
			index = stk.top().second;
			stk.pop();
		}
		else if (!pushed && first) {
			Max = 0;
			break;
		}
		else
			index = primitives.size();

		first = false;
		Max = max(Max, curMax);
		if (Max == S.size()) // Just in case, though I'm pretty sure this was never called
			break;
	}

	fout << Max << endl;

	return 0;
}