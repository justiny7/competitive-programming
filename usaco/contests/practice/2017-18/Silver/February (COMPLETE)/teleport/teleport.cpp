//USACO Silver February 2018 Problem 3

#include <bits/stdc++.h>
#define fi first
#define se second
#define SMALL -1e18
#define BIG 1e18
using namespace std;
typedef long long ll;

ifstream fin("teleport.in");
ofstream fout("teleport.out");

/* Writing down my reasoning here so I make sure I actually understand the problem before attempting it
 * (Got a lot of visualization help from Desmos xd - https://www.desmos.com/calculator/bvmg5k6lgg)
 *
 * For every pile of manure, there may be a collection of 3 points where you can put the teleporter - the first point is the point where it makes the distance smaller to use
 * the teleporter, the second point is the bottommost point - the optimal placement of the teleporter for this particular pile of manure - and the third point is the farthest
 * place you can put the teleporter so that it's the same distance as not using the teleporter at all. This creates a piecewise function, of a straight line, a line with slope
 * -1, a line with slope +1, and 0. This function exists when the distance from 0-a is smaller than the distance from a-b. So, we find all of these slope-change points to trace
 * the parent function - the sum of all these smaller functions, and find the minimum value of this function, which is the least total distance.
 *
 * The sub-functions can be defined as |a|+|b-x|, after we've concluded that |a| < |a-b|. If |a| >= |a-b|, then we might as well not use the teleporter at all because it's either
 * faster or the same distance to get from a->b directly than to go from a->0, then teleport. There are two scenarios for this function. The first is if a<0 && a<b, or if a>=0 &&
 * a>=b, which is when a and b are opposite signs. Then, we're looking for when |a|+|b-x|=|a| (teleport directly the pile cause you only have to move from a to 0), which is at x=b,
 * and |a|+|b-x|=|a-b| (same as not using teleporter), which is at x=0 and 2b. The second is if a<0 && a>=b, or if a>=0 && a<b, which is when a and b are the same sign. These values
 * occur at x=b (direct teleportation), and x=2a and 2b-2a (a little harder to see - check desmos page with a=1 and b=8).
*/

//Update: yay it actually worked

int n;
map<int, int> slope; //map because values go up to 1e8 - too big for an array (also because map automatically sorts the points)
ll cval, cs, cx = SMALL, ans = BIG; //current value, current slope

int main(void) {
    fin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        fin >> a >> b;
        cval += abs(a-b);
        if (abs(a) > abs(a-b))
            continue;
        slope[b] += 2;
        if ((a<0 && a<b) || (a>=0 && a >=b)) {
            slope[0]--;
            slope[2*b]--;
        }
        else if ((a<0 && a>=b) || (a>=0 && a<b)) {
            slope[2*a]--;
            slope[2*(b-a)]--;
        }
    }
    for (pair<int, int> p : slope) {
        cval += cs*(p.fi-cx);
        cs += p.se;
        cx = p.fi;
        ans = min(ans, cval);
    }
    fout << ans << '\n';
}
