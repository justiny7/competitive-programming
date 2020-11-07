/*
ID: justiny7
LANG: C++
TASK: spin
*/

/*
Pretty easy problem, though it took me three tries - 1st try, I forgot to add the repeat check (because I didn't read the rules carefully -_-)
Second time, I put (counter > 0) instead of (counter >= 0) in the very end so rip, and I got it on the third try but forgot to delete the cout
for chkCnter so I got some 0.007s and 0.011s, so I submitted a 4th time and got all 0.004s c:
*/

//And then after reading the solution I realized I could've just cycled through 360 times cuz by then they're gonna go through all the possible
//combinations anyway so I wasted like 10 lines of code and a bit of brainpower -_-

#include <bits/stdc++.h>
using namespace std;

ifstream fin("spin.in");
ofstream fout("spin.out");

//Struct for wedges
struct Wedge {
	int Start;
	int End;
};

//Class for wheels
class Wheel {
public:
	int rotSpeed = 0;
	int numWedges = 0;
	vector<Wedge> wedges;

	Wheel() {}
	Wheel(int spd, int nmWdges, vector<Wedge> wdges) : rotSpeed(spd), numWedges(nmWdges), wedges(wdges) {}
	~Wheel() {};

	void Rotate();
};

//Rotates a wheel
void Wheel::Rotate() {
	for (int i = 0; i < numWedges; i++) {
		wedges[i].Start = (wedges[i].Start + rotSpeed) % 360;
		wedges[i].End = (wedges[i].End + rotSpeed) % 360;
	}
}

Wheel wheels[5];
vector<Wedge> Temp;
int taken[360];
int orig[5][10]; //stores original positions of wheels
int totWedges;

//Rotates the 5 wheels
void rotate() {
	for (int i = 0; i < 5; i++)
		wheels[i].Rotate();
}
//Prints the 5 wheels
void print() {
	for (int i = 0; i < 5; i++) {
		cout << wheels[i].rotSpeed << " " << wheels[i].numWedges << " ";
		for (int j = 0; j < wheels[i].numWedges; j++)
			cout << wheels[i].wedges[j].Start << " " << wheels[i].wedges[j].End;
		cout << endl;
	}
}
//Checks if there is an opening for light shaft
bool check() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < wheels[i].numWedges; j++) {
			if (wheels[i].wedges[j].Start < wheels[i].wedges[j].End)
				for (int p = wheels[i].wedges[j].Start; p <= wheels[i].wedges[j].End; p++)
					taken[p]++;
			else {
				for (int p = wheels[i].wedges[j].Start; p < 360; p++)
					taken[p]++;
				for (int p = 0; p < wheels[i].wedges[j].End; p++)
					taken[p]++;
			}
		}
	}
	for (int i = 0; i < 360; i++)
		if (taken[i] == 5)
			return true;
	return false;
}

int main(void) {
	for (int i = 0; i < 5; i++) {
		int a, b;
		fin >> a >> b;
		totWedges += b;
		for (int j = 0; j < b; j++) {
			Wedge temp;
			fin >> temp.Start >> temp.End;
			temp.End = (temp.End + temp.Start) % 360;
			//cout << temp.Start << " " << temp.End << endl;
			Temp.push_back(temp);
			orig[i][2*j] = temp.Start;
			orig[i][2*j+1] = temp.End;
		}
		wheels[i] = Wheel(a, b, Temp);
		Temp.clear();
	}
	
	int counter = 0;
	while (!check()) {
		//print();
		//cout << endl;
		rotate();
		fill(taken, taken + 360, 0);
		counter++;
		int chkCnter = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < wheels[i].numWedges; j++) {
				if (wheels[i].wedges[j].Start == orig[i][2 * j])
					chkCnter++;
				if (wheels[i].wedges[j].End == orig[i][2 * j + 1])
					chkCnter++;
			}
		//cout << chkCnter << endl;
		if (chkCnter == totWedges*2) {
			counter = -1;
			break;
		}
	}
	//print();
	if (counter >= 0)
		fout << counter << endl;
	else
		fout << "none\n";

	return 0;
}