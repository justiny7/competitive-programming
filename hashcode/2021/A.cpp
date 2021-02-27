#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> vii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpi;

#define INF 1000000000
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define all(x, ...) next(begin(x), ##__VA_ARGS__), end(x)
#define rep(i,a,b) for (int i = a; i <= b; ++i)

int D, I, S, V, F;
int id_count = 0;

typedef struct intersection {
    int ind;
    vector<string> in_streets; // streets coming in
    vector<string> order;
    unordered_map<string, int> time;

} intersection;
vector<intersection> intersections;

typedef struct street {
    /* beginning
     * ending
     * length
     * name
     */
    int B, E, L, id;
    int traffic=0;
    string name;
    void read() { cin >> B >> E >> name >> L; id = ++id_count; intersections[E].in_streets.push_back(name);};
    street() {};
} street;

vector<street> streets(1);
unordered_map<string, int> mrev;

// name -> street id

typedef struct car {
    int P, cur_loc = 0;
    long long total_path_length = 0;
    vector<int> path;
    void read() {
        cin >> P;
        string s;
        for (int i = 0; i < P; ++i) {
            cin >> s;
            total_path_length += streets[mrev[s]].L;
            path.push_back(mrev[s]);
            ++streets[mrev[s]].traffic;
        }
    }

    bool operator<(const car& o) const {
        return total_path_length < o.total_path_length;
    }

    car() {};
} car;

struct comp {
    bool operator()(car a, car b) const {
        return a.total_path_length > b.total_path_length;
    }
};


void print() {
    //cout << I << '\n';
    vector<pair<int, vector<pair<string, int>>>> ans;
    for(int i = 0; i < I; i++) {
        //cout << i << '\n';
        vector<pair<string, int>> here;
        //cout << intersections[i].in_streets.size() << '\n';
        if (i==213234293) {
            sort(intersections[i].in_streets.begin(), intersections[i].in_streets.end(),[&](string a, string b) {
                auto c1=streets[mrev[a]],
                    c2=streets[mrev[b]];
                if (abs(c1.L-c2.L)>300)
                    return c1.L<c2.L;
                return c1.traffic>c2.traffic;
            });
        }
        //else {
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            shuffle(intersections[i].in_streets.begin(), intersections[i].in_streets.end(),std::default_random_engine(seed));
        //}
        for (auto &name : intersections[i].in_streets) {
            intersections[i].order.push_back(name);
            intersections[i].time[name] = 1;
            auto cur_street=streets[mrev[name]];
            if (!cur_street.traffic)
                continue;
            here.emplace_back(name, cur_street.traffic/2+1);
            //cout << name << ' ' << cur_street.traffic << '\n';
            /* cout << name << ' ' << rand() % D + 1 << '\n'; */
        }
        if (!here.size())
            continue;
        ans.emplace_back(i, here);
        //cout << i << '\n';
        //cout << here.size() << '\n';
        //for (auto p:here)
            //cout << p.first << " " << p.second << '\n';
    }
    cout << ans.size() << '\n';
    for (auto p:ans) {
        cout << p.first << '\n' << p.second.size() << '\n';
        if (p.second.size()<=300) {
            for (auto q:p.second)
                cout << q.first << " 1\n";
        }
        else {
            for (auto q:p.second)
                cout << q.first << " " << q.second << '\n';
        }
    }
}

void init() {
    streets.resize(1);
    for(int i = 0; i < I; i++) {
        intersection k;
        k.ind = i;
        intersections.push_back(k);
    }
    mrev.reserve(S);
}

vector<car> cars;
void simulate() {

    for (car x : cars) {
    }
}


int main() {
    //freopen("f.txt", "r", stdin);
    //freopen("F.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> D >> I >> S >> V >> F;

    mrev.reserve(S);
    init();
    for (int i = 0; i < S; ++i) {
        street cur_street;
        cur_street.read();
        streets.push_back(cur_street);
        mrev[cur_street.name] = id_count;
    }

    for (int i = 0; i < V; ++i) {
        car cur_car;
        cur_car.read();
        cars.push_back(cur_car);
    }

    simulate();
    print();

    return 0;
}

