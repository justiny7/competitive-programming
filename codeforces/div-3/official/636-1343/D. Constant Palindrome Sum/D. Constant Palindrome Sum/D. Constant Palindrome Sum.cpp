#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree {
	int pos;
	int height;
};

bool isTaken(int start, int finish, vector<bool> spots) {
	if (start < 0) start = 0;
	if (finish > 1000000000) finish = 1000000000; //get rid of this

	//Insert boundaries into vectors called "boundaries"
	//Boundaries = where tree occupies space, whether down or up
	//Check if interval is open by seeing if there's enough room between that
	//tree and the next boundary

	for (int i = start; i < finish; i++)
		if (spots[i] == true) return true;
	return false;
}

vector<bool> fell(int start, int finish, vector<bool> a) {
	fill(a.begin() + start, a.begin() + finish, true);
	return a;
}

int main(void) {
	int N, counter = 0;
	cin >> N;

	vector<tree> trees;
	vector<bool> taken(10000);

	fill(taken.begin(), taken.end(), false);

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		tree temp;
		temp.pos = a;
		taken[a] = true;
		temp.height = b;
		trees.push_back(temp);
	}

	for (int i = 0; i < trees.size(); i++) {
		//cout << "POS: " << trees[i].pos << "\tHeight: " << trees[i].height << endl;
		if (i != trees.size() - 1 && i != 0 
			&& (!isTaken(trees[i].pos + 1, trees[i].pos + trees[i].height + 1, taken)
			&& isTaken(trees[i].pos - trees[i].height, trees[i].pos, taken))) 
		{
			counter++;
			//cout << "RIGHT\n";
			taken = fell(trees[i].pos + 1, trees[i].pos + trees[i].height + 1, taken);
		}
		else if (i != trees.size() - 1 && i != 0
			&& (isTaken(trees[i].pos + 1, trees[i].pos + trees[i].height + 1, taken)
			&& !isTaken(trees[i].pos - trees[i].height, trees[i].pos, taken)))
		{
			counter++;
			//cout << "LEFT\n";
			taken = fell(trees[i].pos - trees[i].height, trees[i].pos, taken);
		}
		else if (i == 0 || i == trees.size() - 1) counter++;
	}
	for (int i = 0; i < trees.size(); i++) {
		if (i != trees.size() - 1 && i != 0 && !isTaken(trees[i].pos - trees[i].height, trees[i].pos, taken)) {
			counter++;
			//cout << "LEFT\n";
			taken = fell(trees[i].pos - trees[i].height, trees[i].pos, taken);
		}
		else if (i != trees.size() - 1 && i != 0 && !isTaken(trees[i].pos + 1, trees[i].pos + trees[i].height + 1, taken)) {
			counter++;
			//cout << "RIGHT\n";
			taken = fell(trees[i].pos + 1, trees[i].pos + trees[i].height + 1, taken);
		}
	}

	cout << counter << '\n';
	
	//for (int i = 0; i < 30; i++) cout << taken[i] << " ";
	//cout << endl;
	
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canWork(int a, int max, int first, int second) {
	return (first < a || second < a) && (((a - first) <= max) || ((a - second) <= max));

}

struct n {
	int difference;
	int times;

	bool operator() (n i, n j) { return (i.times > j.times); }
} opN;

int main(void) {
	int t;
	cin >> t;

	vector<vector<int>> arrays;
	vector<int> k;
	for (int i = 0; i < t; i++) {
		int a, c;
		cin >> a >> c;
		k.push_back(c);
		vector<int> temp;
		for (int j = 0; j < a; j++) {

			int b;
			cin >> b;
			temp.push_back(b);
		}
		arrays.push_back(temp);
	}

	//Strategy: Iterate through arrays[i], count how many occurences there are of each sum. Then,
	//          start from the greatest occurence, checking if it's possible to achieve that sum
	//          with the elements of the array; if yes, cout and break. If no, move on to the
	//          next-greatest occurence

	for (int i = 0; i < t; i++) {
		int MAX = k[i], counter = 0, counter2 = 0;
		int currentSum, lastSum, size = arrays[i].size();
		vector <int> occurences(2 * k[i] + 1); //1-based indexing
		vector <n> times;
		fill(occurences.begin(), occurences.end(), 0);

		for (int j = 0; j < size / 2; j++) {
			if (j != 0) lastSum = currentSum;
			currentSum = arrays[i][j] + arrays[i][size - (j + 1)];
			occurences[currentSum]++;

			//cout << "CurrentSum: " << currentSum << endl;
			//if (j != 0) cout << "LastSum: " << lastSum << endl;

			if (j != 0 && lastSum == currentSum) counter2++;
		}

		//for (int j = 0; j < occurences.size(); j++) cout << occurences[j] << " ";
		//cout << endl;

		if (counter2 + 1 == size / 2) cout << "0\n";
		else {
			for (int j = 0; j < occurences.size(); j++) {
				if (occurences[j] != 0) {
					n N;
					N.difference = j;
					N.times = occurences[j];
					times.push_back(N);
				}
			}
			sort(times.begin(), times.end(), opN);
			int failcount = 0;
			for (int p = 0; p < times.size(); p++) {
				//cout << times[p].times << " " << times[p].difference << endl;
				for (int j = 0; j < size / 2; j++) {
					if (canWork(times[p].difference, MAX, arrays[i][j], arrays[i][size - (j + 1)]) == false) {
						//cout << times[p].difference << " failed" << endl;
						failcount++;
						counter = 0;
						break;
					}
					else counter++;
				}
				if (counter == size / 2) {
					cout << size/2 - times[p].times << '\n';
					break;
				}
			}
			if (failcount == times.size()) cout << size / 2 << '\n';
			
		}
		

	}

	return 0;
}

*/