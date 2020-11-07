/*
ID: justiny7
TASK: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    string temp1;
    string temp2;

    fin >> temp1 >> temp2;

    int answer = 1;
    for (int i = 0; i < temp1.length(); i++)
    {
        answer *= (temp1[i] - 'A' + 1);
        cout << (temp1[i] - 'A' + 1) << '\t' << "-->" << '\t' << temp1[i] << endl;
    }

    cout << endl << endl;

    int comet = 1;
    for (int i = 0; i < temp2.length(); i++)
    {
        comet *= (temp2[i] - 'A' + 1);
        cout << (temp2[i] - 'A' + 1) << '\t' << "-->" << '\t' << temp2[i] << endl;
    }

    int c = answer % 47;

    cout << endl << c << endl << comet  % 47;

    if (c == (comet % 47)) {
        cout << "\nYay\n";
        fout << "GO\n";
    }

    else {
        cout << "\nrip\n";
        fout << "STAY\n";
    }

    return 0;
}
