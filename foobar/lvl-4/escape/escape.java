/*  PROBLEM STATEMENT
    Escape Pods
    ===========

    You've blown up the LAMBCHOP doomsday device and broken the bunnies out
    of Lambda's prison - and now you need to escape from the space station as
    quickly and as orderly as possible! The bunnies have all gathered in various
    locations throughout the station, and need to make their way towards the
    seemingly endless amount of escape pods positioned in other parts of the
    station. You need to get the numerous bunnies through the various rooms to
    the escape pods. Unfortunately, the corridors between the rooms can only fit
    so many bunnies at a time. What's more, many of the corridors were resized to
    accommodate the LAMBCHOP, so they vary in how many bunnies can move through
    them at a time.

    Given the starting room numbers of the groups of bunnies, the room numbers of
    the escape pods, and how many bunnies can fit through at a time in each direction
    of every corridor in between, figure out how many bunnies can safely make it to
    the escape pods at a time at peak.

    Write a function solution(entrances, exits, path) that takes an array of integers
    denoting where the groups of gathered bunnies are, an array of integers denoting
    where the escape pods are located, and an array of an array of integers of the
    corridors, returning the total number of bunnies that can get through at each time
    step as an int. The entrances and exits are disjoint and thus will never overlap.
    The path element path[A][B] = C describes that the corridor going from A to B can
    fit C bunnies at each time step.  There are at most 50 rooms connected by the
    corridors and at most 2000000 bunnies that will fit at a time.

    For example, if you have:
    entrances = [0, 1]
    exits = [4, 5]
    path = [
      [0, 0, 4, 6, 0, 0],  # Room 0: Bunnies
      [0, 0, 5, 2, 0, 0],  # Room 1: Bunnies
      [0, 0, 0, 0, 4, 4],  # Room 2: Intermediate room
      [0, 0, 0, 0, 6, 6],  # Room 3: Intermediate room
      [0, 0, 0, 0, 0, 0],  # Room 4: Escape pods
      [0, 0, 0, 0, 0, 0],  # Room 5: Escape pods
    ]

    Then in each time step, the following might happen:
    0 sends 4/4 bunnies to 2 and 6/6 bunnies to 3
    1 sends 4/5 bunnies to 2 and 2/2 bunnies to 3
    2 sends 4/4 bunnies to 4 and 4/4 bunnies to 5
    3 sends 4/6 bunnies to 4 and 4/6 bunnies to 5

    So, in total, 16 bunnies could make it to the escape pods at 4 and 5 at each time
    step.  (Note that in this example, room 3 could have sent any variation of 8 bunnies
    to 4 and 5, such as 2/6 and 6/6, but the final solution remains the same.)

    Languages
    =========

    To provide a Java solution, edit Solution.java
    To provide a Python solution, edit solution.py

    Test cases
    ==========
    Your code should pass the following test cases.
    Note that it may also be run against hidden test cases not shown here.

    -- Java cases --
    Input:
    Solution.solution({0, 1}, {4, 5}, {{0, 0, 4, 6, 0, 0}, {0, 0, 5, 2, 0, 0},
        {0, 0, 0, 0, 4, 4}, {0, 0, 0, 0, 6, 6}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}})
    Output:
        16

    Input:
    Solution.solution({0}, {3}, {{0, 7, 0, 0}, {0, 0, 6, 0}, {0, 0, 0, 8}, {9, 0, 0, 0}})
    Output:
        6

    -- Python cases --
    Input:
    solution.solution([0], [3], [[0, 7, 0, 0], [0, 0, 6, 0], [0, 0, 0, 8], [9, 0, 0, 0]])
    Output:
        6

    Input:
    solution.solution([0, 1], [4, 5], [[0, 0, 4, 6, 0, 0], [0, 0, 5, 2, 0, 0],
        [0, 0, 0, 0, 4, 4], [0, 0, 0, 0, 6, 6], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]])
    Output:
        16
*/

/* IDEA
 * It's just max flow w/ multiple sources and sinks, so create a supersource that
 * leads to all sources and a supersink where all sinks flow to and run max flow
 * on that
*/

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class escape {
    public static void main(String[] args) {
        //System.out.println(solution(new int[]{0,1},new int[]{4,5},new int[][]
            //{{0,0,4,6,0,0},
             //{0,0,5,2,0,0},
             //{0,0,0,0,4,4},
             //{0,0,0,0,6,6},
             //{0,0,0,0,0,0},
             //{0,0,0,0,0,0}}));
        System.out.println(solution(new int[]{0}, new int[]{3}, new int[][]
            {{0,7,0,0},
             {0,0,6,0},
             {0,0,0,8},
             {9,0,0,0}}));
    }

    static final int mxN=61;
    static int[][] adj=new int[mxN][mxN]; //supersource=55, supersink=57

    public static int solution(int[] entrances, int[] exits, int[][]paths) {
        int n=paths.length;
        Graph g=new Graph(n);
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (paths[i][j]>0)
                    g.addEdge(i, j, paths[i][j]);
        for (int i=0; i<entrances.length; ++i)
            g.addEdge(55, entrances[i], (int)2e9);
        for (int i=0; i<exits.length; ++i)
            g.addEdge(exits[i], 57, (int)2e9);
        return g.dinic();
    }

    public static class Edge {
        public int v, flow, c, rev;
        public Edge(int v, int flow, int c, int rev) {
            this.v=v;
            this.flow=flow;
            this.c=c;
            this.rev=rev;
        }
    }

    public static class aList {
        public ArrayList<Edge> lst;
        public aList() {
            lst=new ArrayList<Edge>();
        }
    }

    public static class Graph {
        public int n;
        public int lvl[]=new int[mxN];
        public int start[]=new int[mxN];
        public aList[] adj=new aList[mxN];

        public Graph(int n) {
            this.n=n;
            for (int i=0; i<mxN; ++i)
                adj[i]=new aList();
        }
        public void addEdge(int u, int v, int cap) {
            Edge a=new Edge(v, 0, cap, adj[v].lst.size());
            Edge b=new Edge(u, 0, 0, adj[u].lst.size());
            adj[u].lst.add(a);
            adj[v].lst.add(b);
        }
        boolean bfs() {
            for (int i=0; i<mxN; ++i)
                lvl[i]=-1;
            lvl[55]=0;
            Queue<Integer> q=new LinkedList<Integer>();
            q.add(55);
            while (!q.isEmpty()) {
                int t=q.remove();
                for (Edge e:adj[t].lst)
                    if (lvl[e.v]<0 && e.flow<e.c) {
                        lvl[e.v]=lvl[t]+1;
                        q.add(e.v);
                    }
            }
            if (lvl[57]>=0)
                return true;
            return false;
        }
        int send(int cur, int flo) {
            if (cur==57)
                return flo;
            while (start[cur]<adj[cur].lst.size()) {
                Edge e=adj[cur].lst.get(start[cur]);
                if (lvl[e.v]==lvl[cur]+1 && e.flow<e.c) {
                    int cmin=Math.min(flo, e.c-e.flow);
                    int tflo=send(e.v, cmin);
                    if (tflo>0) {
                        e.flow+=tflo;
                        adj[e.v].lst.get(e.rev).flow-=tflo;
                        return tflo;
                    }
                }
                ++start[cur];
            }
            return 0;
        }
        int dinic() {
            int tot=0;
            while (bfs()==true) {
                for (int i=0; i<mxN; ++i)
                    start[i]=0;
                int f=send(55, (int)2e9);
                while (f>0) {
                    tot+=f;
                    f=send(55, (int)2e9);
                }
            }
            return tot;
        }
    }
}

