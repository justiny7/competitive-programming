/*
ID: justiny7
LANG: C++
TASK: stall4
*/

#include <bits/stdc++.h>
using namespace std;

//Frick I'm so stupid I skimmed over the Network Flow doc and didn't read about maximum matching smh
ifstream fin("stall4.in");
ofstream fout("stall4.out");

int n, m, ans = -1, totflow, maxflow, maxloc, flow[500], prevn[500], capacity[500][500]; //0 = source, m+1 = sink
bool visited[201];

int main(void) {
	fin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int a;
		fin >> a;
		capacity[0][i+m+1] = 1;
		for (int j = 0; j < a; j++) {
			int b;
			fin >> b;
			capacity[i+m+1][b] = 1;
			capacity[b][m+1] = 1;
		}
	}
	/*
	for (int i = 0; i <= n+m+1; i++) {
		for (int j = 1; j <= m+1; j++)
			cout << capacity[i][j] << " ";
		cout << '\n';
	}*/

	//just copy/pasted my ditches code
	while (true) {
		for (int i = 0; i <= n+m+1; i++) {
			prevn[i] = -1;
			flow[i] = 0;
			visited[i] = false;
		}
		flow[0] = 2e9;

		while (true) {
			maxflow = 0;
			maxloc = -1;

			for (int i = 0; i <= n+m+1; i++)
				if (!visited[i] && flow[i] > maxflow) {
					maxflow = flow[i];
					maxloc = i;
				}

			if (maxloc == -1)
				break;

			//cout << "maxloc: " << maxloc << '\n';

			visited[maxloc] = true;
			for (int i = 0; i <= n+m+1; i++)
				if (!visited[i] && flow[i] < min(maxflow, capacity[maxloc][i])) {
					prevn[i] = maxloc;
					flow[i] = min(maxflow, capacity[maxloc][i]);
				}
		}

		if (flow[m+1] == 0)
			break;

		int pathcap = flow[m+1];
		totflow += pathcap;

		int cur = m+1, next;
		while (cur != 0) {
			next = prevn[cur];
			capacity[next][cur] -= pathcap;
			capacity[cur][next] += pathcap;
			cur = next;
		}
	}

	//cout << totflow << '\n';
	fout << totflow << '\n';
	
	return 0;
}

/* Old stuff

vector<vector<int>> cows;

void print() {
	for (int i = 0; i < cows.size(); i++) {
		cout << "cow: " << i << "\nstalls: ";
		for (int j = 0 ; j < cows[i].size(); j++)
			cout << cows[i][j] << " ";
		cout << '\n';
	}
}

//removes stall
void remove(int x) {
	for (int i = 0; i < cows.size(); i++) {
		int t = lower_bound(cows[i].begin(), cows[i].end(), x) - cows[i].begin();
		if (cows[i][t] == x)
			cows[i].erase(cows[i].begin()+t);
	}
	sort(cows.begin(), cows.end(), sortMethod);
}

bool sortMethod(vector<int> a, vector<int> b) {
	if (a.size() != b.size())
		return (a.size() < b.size());
	else {
		for (int i = 0; i < a.size(); i++)
			if (a[i] != b[i])
				return a[i] < b[i];
	}
	return true;
}

vector<vector<string>> stalls (2);
bool stall[201];



	int curcow = 0;
	string open;
	for (int i = 0; i < m; i++)
		open.push_back('1');
	
	bool first = true;
	while (cows.size() > 0) {
		//cout << "here\n";
		sort(stalls[0].begin(), stalls[0].end());
		sort(cows.begin(), cows.end(), sortMethod);
		//cout << "here2\n";
		//cout << '\n';
		//print();

		string temp;
		if (first) {
			temp = open;
			for (int j : cows[0]) {
				cout << j << '\n';
				temp[j-1] = '0';
				stalls[1].push_back(temp);
				//cout << "Seq: " << temp << '\n';
				temp[j-1] = '1';
				remove(j);
			}
			//cout << "here3\n";
		}
		else {
			for (int j = 0; j < stalls[0].size(); j++) {
				bool add = false;
				temp = stalls[0][j];
				for (int p : cows[0]) {
					if (temp[p-1] == '1') {
						temp[p-1] = '0';
						if (!binary_search(stalls[1].begin(), stalls[1].end(), temp))
							stalls[1].push_back(temp);
						//cout << "Seq: " << temp << '\n';
						temp[p-1] = '1';
						add = true;
						remove(p);
					}
				}
				if (!add)
					stalls[1].push_back(temp);
			}
		}
		cows.erase(cows.begin());
		first = false;
		//i = 0;
		stalls[0] = stalls[1];
		//cout << stalls[0].size() << '\n';
		stalls[1].clear();
	}

	cout << stalls[0].size() << '\n';
	for (int i = 0; i < stalls[0].size(); i++) {
		int curcnt = 0;
		//cout << stalls[0][i] << '\n';
		for (int j = 0; j < stalls[0][i].length(); j++)
			if (stalls[0][i][j] == '0')
				curcnt++;
		ans = max(ans, curcnt);
	}

	if (ans == -1)
		ans = 0;
	*/



	/* more old stuff
	for (int i = 1; i <= m; i++) {
		bool done = false;
		sort(cows.begin(), cows.end(), sortMethod);
		for (int j = 0; j < cows.size(); j++) {
			for (int p : cows[j])
				if (p == i) {
					ans++;
					remove(i);
					cows.erase(cows.begin()+j);
					done = true;
					break;
				}
			if (done)
				break;
		}
	}*/