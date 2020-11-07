/*
ID: justiny7
LANG: C++
TASK: race3
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("race3.in");
ofstream fout("race3.out");

vector<int> out[51], unavoidable, split;
int a, n = 0;

void print() {
	for (int i = 0; i < n; i++) {
		cout << i << ": ";
		for (int p : out[i])
			cout << p << " ";
		cout << " -\n";
	}
}

int main(void) {
	while (true) {
		fin >> a;
		if (a == -2) {
			n++;
			continue;
		}
		if (a == -1)
			break;
		if (a == n)
			continue;
		out[n].push_back(a);
	}

	//print();
	for (int i = 1; i <= n-2; i++) {
		bool avoid = false, visited[51];
		fill(visited, visited+n, false);
		visited[i] = true;
		stack<int> st;
		st.push(0);
		//Basically delete node (set it to visited), DFS from start to finish - if path exists, then it's not unavoidable
		while (!st.empty() && !avoid) {
			int t = st.top();
			st.pop();
			visited[t] = true;
			for (int neigh : out[t]) {
				if (neigh == n-1) {
					avoid = true;
					break;
				}
				else if (!visited[neigh])
					st.push(neigh);
			}
		}
		if (!avoid) {
			/*
				- If it's unavoidable, DFS to see if it touches itself - if it does, then it's not a splitting point
				- Whoops, only if goes before the point (added indexes)
				- Still got everything right but realized indexes won't work - took out resetting "visited", then checking if neighbors were
				  already visited
			*/
			//for (int i = 0; i < n; i++)
			//	cout << visited[i] << " ";
			//cout << '\n';

			unavoidable.push_back(i);
			bool splitting = true, vis2[51];
			fill(vis2, vis2+n, false);
			visited[i] = false;
			stack<int> spl;
			spl.push(i);

			while (!spl.empty() && splitting) {
				int t = spl.top();
				spl.pop();
				if (t != i)
					vis2[t] = true;
				//cout << "neighbors of " << t << ":\n";
				for (int neigh : out[t]) {
					//cout << neigh << " ";
					if (visited[neigh]) {
						//cout << "node: " << i << "\nHit: " << neigh << '\n';
						splitting = false;
						break;
					}
					else if (!vis2[neigh])
						spl.push(neigh);
					//cout << '\n';
				}
			}
			if (splitting)
				split.push_back(i);
		}
	}

	fout << unavoidable.size();
	for (int g : unavoidable)
		fout << " " << g;
	fout << '\n' << split.size();
	for (int g : split)
		fout << " " << g;
	fout << '\n';

	return 0;
}