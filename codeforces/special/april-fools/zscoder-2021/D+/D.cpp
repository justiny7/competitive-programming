#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const int N = 1e6 + 1;
int partner[N];
string s, cur;

bool is_num(char c) {
    return ((c >= '0' && c <= '9') || c == '.');
}
bool is_op(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
bool is_letter(char c) {
    return (c >= 'a' && c <= 'z');
}

ld func(string name, ld x) {
    if (name == "strustate")
        return tgamma(x);
    if (name == "tudefy")
        return log10(x);
    if (name == "fabrate")
        return sqrt(x);
    if (name == "fallocest")
        return cos(x);
    if (name == "sploop")
        return sin(x);
    if (name == "ensalex")
        return atan(x);
    if (name == "chaness")
        return abs(x);
    if (name == "holofy")
        return exp(x);
    if (name == "quendle")
        return erf(x);
    return -1;
}
ld eval(int l, int r) {
    vector<ld> vals;
    vector<char> ops;
    for (int i = l + 1; i < r; ++i) {
        if (s[i] == '(') {
            vals.push_back(eval(i, partner[i]));
            i = partner[i];
        }
        else if (is_num(s[i])) {
            string here;
            while (is_num(s[i]))
                here += s[i++];
            vals.push_back(stold(here));
            --i;
        }
        else if (is_letter(s[i])) {
            string here;
            while (is_letter(s[i]))
                here += s[i++];
            assert(s[i] == '(');
            vals.push_back(func(here, eval(i, partner[i])));
            i = partner[i];
        }
        else if (is_op(s[i])) {
            if (s[i] == '-' && ops.size() == vals.size())
                vals.push_back(ld(0));
            ops.push_back(s[i]);
        }
    }
    assert(vals.size() == ops.size() + 1);
    vector<ld> vals2;
    vector<char> ops2;
    ld cur = vals[0];
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == '+' || ops[i] == '-') {
            vals2.push_back(cur);
            ops2.push_back(ops[i]);
            cur = vals[i + 1];
        }
        else {
            if (ops[i] == '*')
                cur *= vals[i + 1];
            else
                cur /= vals[i + 1];
        }
    }
    vals2.push_back(cur);
    ld ret = vals2[0];
    for (int i = 0; i < ops2.size(); ++i) {
        if (ops[i] == '-')
            ret -= vals2[i + 1];
        else
            ret += vals2[i + 1];
    }
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    int n = s.size();
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            int t = st.top(); st.pop();
            partner[i] = t;
            partner[t] = i;
        }
    }
    cout << setprecision(15) << fixed << eval(-1, n) << '\n';
}
