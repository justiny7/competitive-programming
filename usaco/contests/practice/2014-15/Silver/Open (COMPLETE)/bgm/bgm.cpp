//USACO Silver US Open 2015 Problem 1
#include <bits/stdc++.h>
using namespace std;
using ll=long long; 
//C++ negative modulos are weird - 3rd submission 
ifstream fin("bgm.in");
ofstream fout("bgm.out");

int n;
ll ans;
map<char, int[7]> nums;

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i) {
        char c;
        int a;
        fin >> c >> a;
        nums[c][(a%7+7)%7]++; //negative mod returns first mod<0, so +7 then %7 works for both + and - cases
    }
    for (int b=0; b<7; ++b) //find all mod7, test every case
        for (int s=0; s<7; ++s)
            for (int i=0; i<7; ++i)
                for (int o=0; o<7; ++o)
                    for (int e=0; e<7; ++e)
                        for (int m=0; m<7; ++m)
                            for (int g=0; g<7; ++g)
                                if (((b+i+2*(s+e))*(g+o+e+s)*(m+2*o))%7==0) {
                                    ans+=(ll)nums['B'][b]*nums['S'][s]*nums['O'][o]*nums['E'][e]*
                                        nums['I'][i]*nums['M'][m]*nums['G'][g];
                                }
    fout << ans << '\n';
}
