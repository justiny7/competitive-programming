/*
ID: justiny7
LANG: C++
TASK: wormhole
*/

#include <bits/stdc++.h>
using namespace std;

ifstream fin("wormhole.in");
ofstream fout("wormhole.out");

int n, counter, pairing[13], nright[13];
vector<pair<int, int>> wormholes;

bool noCycle() {
    for (int i = 1; i <= n; i++) {
        int curhole = i;
        for (int j = 0; j < n; j++) {
            curhole = nright[pairing[curhole]];
            if (curhole == -1)
                break;
        }
        if (curhole > -1)
            return false;
    }
    return true;
}

void solve(int paircount) {
    if (paircount*2 == n && !noCycle()) {
        counter++;
        //cout << '\n';
        return;
    }
    int next_unpaired = 1;
    while (pairing[next_unpaired] > 0)
        next_unpaired++;

    for (int i = next_unpaired+1; i <= n; i++) {
        if (pairing[i] > 0)
            continue;
        pairing[next_unpaired] = i;
        pairing[i] = next_unpaired;
        //cout << i << " is paired with " << next_unpaired << '\n'; 
        solve(paircount+1);
        pairing[i] = pairing[next_unpaired] = 0;
    }
    
}

int main(void) {
    fin >> n;
    wormholes.resize(n+1);
    for (int i = 1; i <= n; i++)
        fin >> wormholes[i].second >> wormholes[i].first;
    sort(wormholes.begin()+1, wormholes.end());
    for (int i = 1; i <= n; i++) {
        if (i < n && wormholes[i].first == wormholes[i+1].first)
            nright[i] = i+1;
        else
            nright[i] = -1;
    }

    //for (int i = 1; i <= n; i++)
    //    cout << nright[i] <<  " ";
    //cout << "\n\n";
    solve(0);
    fout << counter << '\n';

    return 0;
}



/* Old stuff that ran too slowly
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

struct Hole {
	int x;
	int y;
	int ID;
	int pair;

	bool operator() (Hole i, Hole j) {
		return (i.y < j.y);
	}
} hole;



int main(void) {
	ifstream in("wormhole.in");
	ofstream out("wormhole.out");

	int counter = 0; //to count the # of possibilities

	int N; //# of wormholes, 2-12 even
	in >> N;
	
	vector <Hole> wormholes;
	vector<vector<Hole>> sameRow;

	for (int i = 0; i < N; i++) {
		int X, Y;
		in >> X >> Y;
		Hole temp;
		temp.x = X;
		temp.y = Y;
		temp.ID = i;
		wormholes.push_back(temp);
	}



	return 0;
}
*/
/* DITCHING THIS IDEA - trying to manually count # of possibilties by seeing how many are in each row
	sort(wormholes.begin(), wormholes.end(), hole);

	for (int i = 0; i < N; i++) {
		cout << wormholes[i].ID << " " << wormholes[i].x << " " << wormholes[i].y << endl;
	}
	*/

	/*
	vector<Hole> temp;
	for (int i = 0; i < N; i++) { //Sorts wormholes into rows
		Hole temp2 = wormholes[i];
		temp.push_back(temp2);

		if (i != N - 1 && temp2.y != wormholes[i + 1].y) {
			sameRow.push_back(temp);
			temp.clear();
		}
		else if (i == N - 1) sameRow.push_back(temp);
	}
	temp.clear(); //In case we need it again later
	/*
	for (int i = 0; i < sameRow.size(); i++) {
		//cout << sameRow.size();
		for (int j = 0; j < sameRow[i].size(); j++) {
			//cout << sameRow[i].size();
			cout << i << " " << sameRow[i][j].y << endl;
		}
	}
	*/
	/*
	int numRows = sameRow.size();
	vector<int> pairsPerRow; //Pairs per row;

	for (int i = 0; i < numRows; i++) {
		pairsPerRow.push_back(sameRow[i].size() - 1);
		//cout << pairsPerRow[i] << " ";
	}
	*/
