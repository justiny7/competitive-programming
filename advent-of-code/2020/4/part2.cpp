#include <bits/stdc++.h>
using namespace std;

const string ecl[]={
    "amb",
    "blu",
    "brn",
    "gry",
    "grn",
    "hzl",
    "oth"
};

int get(string s) {
    int ret=0;
    for (char c:s)
        ret=ret*10+(c-'0');
    return ret;
}
bool get_hgt(string s) {
    int ret=0;
    string type;
    for (int i=0; i<s.size(); ++i) {
        if (s[i]>='0' && s[i]<='9')
            ret=ret*10+(s[i]-'0');
        else
            type.push_back(s[i]);
    }
    if (type=="cm")
        return (ret>=150 && ret<=193);
    return (ret>=59 && ret<=76);
}
bool get_hcl(string s) {
    if (s.size()!=7)
        return 0;
    bool f=1;
    for (int i=1; i<7; ++i)
        f&=((s[i]>='0' && s[i]<='9') || (s[i]>='a' && s[i]<='f'));
    return (f && s[0]=='#');
}
bool get_ecl(string s) {
    for (int i=0; i<7; ++i)
        if (s==ecl[i])
            return 1;
    return 0;
}

int main() {
    freopen("test.txt", "r", stdin);
    string s;
    int ans=0, f=0;
    map<string, string> mp;
    while (1) {
        getline(cin, s);
        if (s.empty()) {
            if (f)
                break;
            else {
                bool f2=1;
                int byr=get(mp["byr"]),
                    iyr=get(mp["iyr"]),
                    eyr=get(mp["eyr"]);
                f2&=(byr>=1920 && byr<=2002);
                f2&=(iyr>=2010 && iyr<=2020);
                f2&=(eyr>=2020 && eyr<=2030);
                f2&=get_hgt(mp["hgt"]);
                f2&=get_hcl(mp["hcl"]);
                f2&=get_ecl(mp["ecl"]);
                f2&=(mp["pid"].size()==9);
                if (f2)
                    ++ans;
                f=1;
                mp.clear();
            }
            continue;
        }
        f=0;
        stringstream ss(s);
        string s2;
        while (ss >> s2)
            mp[s2.substr(0, 3)]=s2.substr(4);
    }
    cout << ans << '\n';
}

