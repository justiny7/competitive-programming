/*
ID: justiny7
LANG: C++
TASK: shopping
*/

//Multiple Knapsack Problem I think
//Recursive search too slow - trying dp method that I was too lazy to try earlier...

#include <bits/stdc++.h>
using namespace std;

ifstream fin("shopping.in");
ofstream fout("shopping.out");

struct Item {
    int code;
    int quant;
};

struct Deal {
    int price;
    vector<Item> items;
};

int nItems, nDeals, codeCnt, codeTag[1000]; //Tag of 0-5 for each item
vector<Deal> deals; //Holds all the deals
int dp[6][6][6][6][6]; //Holds min price for items with (up to) 5 of each type of item
int singlePrice[5], whatwewant[5]; //Price for single item of code i, how much of item i we want

int main(void) {
    fin >> nDeals;
    for (int i = 0; i < 1000; i++)
        codeTag[i] = -1;
    for (int i = 0; i < nDeals; i++) {
        Deal temp3;
        vector<Item> temp2;
        int num;
        fin >> num;
        for (int j = 0; j < num; j++) {
            Item temp;
            fin >> temp.code >> temp.quant;
            if (codeTag[temp.code] < 0) {
                codeTag[temp.code] = codeCnt;
                temp.code = codeCnt;
                codeCnt++;
            }
            else 
                temp.code = codeTag[temp.code];
            
            temp2.push_back(temp);
        }
        int p;
        fin >> p;
        temp3.price = p;
        temp3.items = temp2;
        deals.push_back(temp3);
    }
    fin >> nItems;
    for (int i = 0; i < nItems; i++) {
        int c, q, p;
        fin >> c >> q >> p;
        if (codeTag[c] < 0) {
                codeTag[c] = codeCnt;
                c = codeCnt;
                codeCnt++;
            }
            else 
                c = codeTag[c];
        
        whatwewant[c] = q;
        singlePrice[c] = p;
    }
    /*
    for (int i = 0; i < deals.size(); i++) {
        cout << "price: " << deals[i].price << endl;
        cout << "Items:\n";
        for (int j = 0; j < deals[i].items.size(); j++)
            cout << deals[i].items[j].quant << " many of " << deals[i].items[j].code << endl;
        cout << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << "Price for " << i << ": " << singlePrice[i] << endl;
        cout << "How many of " << i << " we want: " << whatwewant[i] << endl;
    }
    cout << endl;
    */
    for (int a = 0; a <= whatwewant[0]; a++) {
        for (int b = 0; b <= whatwewant[1]; b++) {
            for (int c = 0; c <= whatwewant[2]; c++) {
                for (int d = 0; d <= whatwewant[3]; d++) {
                    for (int e = 0; e <= whatwewant[4]; e++) { //Cycle through all possible baskets
                        int curPrice = singlePrice[0]*a + singlePrice[1]*b + singlePrice[2]*c + singlePrice[3]*d + singlePrice[4]*e;
                        //cout << "current price:" << curPrice << endl;
                        for (int m = 0; m < nDeals; m++) {
                            int howMany[5]; //To see how many of each item this deal has
                            fill(howMany, howMany+5, 0); //MAKE SURE IT'S ALL 0 TO START that's what I forgot
                            for (int i = 0; i < deals[m].items.size(); i++)
                                howMany[deals[m].items[i].code] = deals[m].items[i].quant;
                            if ((howMany[0] <= a) && (howMany[1] <= b) && (howMany[2] <= c) && (howMany[3] <= d) && (howMany[4] <= e)) {
                                int newPrice = deals[m].price + dp[a-howMany[0]][b-howMany[1]][c-howMany[2]][d-howMany[3]][e-howMany[4]];
                                curPrice = min(curPrice, newPrice); //Check if adding this deal is cheaper than not using it
                                //cout << "New price:" << newPrice << endl;
                                //print();
                            }
                        }
                        dp[a][b][c][d][e] = curPrice;
                        //cout << a << b << c << d << e << endl;
                        //cout << dp[a][b][c][d][e] << "\n\n";
                    }
                }
            }
        }
    }

    fout << dp[whatwewant[0]][whatwewant[1]][whatwewant[2]][whatwewant[3]][whatwewant[4]] << endl;

    return 0;
}

/* Old stuff that was too slow
void print() {
    for (int i = 0; i < 5; i++)
        cout << "Item #" << i << ": " << whatwewant[i] << endl;
    cout << endl;
}

bool Done() {
    int counter = 0;
    for (int i = 0; i < whatwewant.size(); i++)
        if (whatwewant[i] == 0)
            counter++;
    if (counter == whatwewant.size())
        return true;
    return false;
}

bool canAdd(int index) {
    for (int i = 0; i < deals[index].second.size(); i++) {
        int a = whatwewant[deals[index].second[i].code] - deals[index].second[i].quant;
        if (a < 0)
            return false;
    }
    return true;
}

void solve(int curCost) {
    //cout << "Cost: " << curCost << endl;
    //print();
    if (Done()) {
        cost = min(cost, curCost);
        return;
    }
    for (int index = 0; index < deals.size(); index++) {
        //cout << "deal index: " << index << endl;
        int addCount = 0;
        if (canAdd(index)) {
            while (canAdd(index)) {
                addCount++;
                for (int i = 0; i < deals[index].second.size(); i++) {
                    whatwewant[deals[index].second[i].code] -= deals[index].second[i].quant;
                    //cout << whatwewant[deals[index].second[i].code] << " ";
                }
            }
            //cout << endl;
            curCost += addCount * deals[index].first;
            solve(curCost);
            curCost -= addCount * deals[index].first;
            for (int q = 0; q < addCount; q++) {
                for (int i = 0; i < deals[index].second.size(); i++)
                    whatwewant[deals[index].second[i].code] += deals[index].second[i].quant;
            }
        }
    }
}
*/