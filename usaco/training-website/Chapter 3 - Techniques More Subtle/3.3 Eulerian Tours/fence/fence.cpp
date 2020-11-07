/*
ID: justiny7
LANG: C++
TASK: fence
*/

//Trying out VS Code for the first time - I think I like it more than the normal Visual Studio

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");

int F, pos, maxInt, minInt = 1e9, first = 1e9;
vector<vector<int>> adjList (501);
vector<int> circuit;

void tour(int node) {
    int numneigh = adjList[node].size();
    //cout << "size: " << numneigh << endl;
    if (numneigh == 0) {
        circuit[pos] = node;
        pos++;
    }
    else {
        while (adjList[node].size() > 0) {
            int del = adjList[node][adjList[node].size()-1]; //whoops shld've saved this as 0, then I can sort
            //cout << "neighbor: " << del << endl;           //normally down there instead of using greater<int>()
            adjList[node].pop_back();
            for (int i = 0; i < adjList[del].size(); i++)
                if (adjList[del][i] == node) {
                    adjList[del].erase(adjList[del].begin() + i);
                    break;
                }
            tour(del);
        }
        circuit[pos] = node;
        pos++;
    }
}

int main(void) {
    fin >> F;
    //cout << "F: " << F << endl;
    for (int i = 0; i < F; i++) {
        int a, b;
        fin >> a >> b;
        //cout << a << " is connected to " << b << endl;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
        maxInt = max(a, maxInt);
        maxInt = max(b, maxInt);
        minInt = min(a, minInt);
        minInt = min(b, minInt);
    }

    for (int i = 1; i <= maxInt; i++) {
        sort(adjList[i].begin(), adjList[i].end(), greater<int>());
        /*cout << "neighs of " << i << endl;
        for (int j : adjList[i])
            cout << j << " ";
        cout << endl;*/
        if (adjList[i].size() != 0 && adjList[i].size() % 2 == 1 && i < first)
            first = i;
    }

    if (first > 1000000)
        first = minInt;
    
    circuit.resize(F+1);
    tour(first);
    reverse(circuit.begin(), circuit.end());
    for (int i : circuit)
        if (i != 0)
            fout << i << endl;

    return 0;
}
