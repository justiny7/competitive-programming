/* PROBLEM STATEMENT
   Bringing a Gun to a Guard Fight
   ===============================

   Uh-oh - you've been cornered by one of Commander Lambdas elite guards! Fortunately,
   you grabbed a beam weapon from an abandoned guard post while you were running through
   the station, so you have a chance to fight your way out. But the beam weapon is
   potentially dangerous to you as well as to the elite guard: its beams reflect off
   walls, meaning you'll have to be very careful where you shoot to avoid bouncing a
   shot toward yourself!

   Luckily, the beams can only travel a certain maximum distance before becoming too
   weak to cause damage. You also know that if a beam hits a corner, it will bounce back
   in exactly the same direction. And of course, if the beam hits either you or the guard,
   it will stop immediately (albeit painfully).

   Write a function solution(dimensions, your_position, guard_position, distance) that gives
   an array of 2 integers of the width and height of the room, an array of 2 integers of your
   x and y coordinates in the room, an array of 2 integers of the guard's x and y coordinates
   in the room, and returns an integer of the number of distinct directions that you can fire
   to hit the elite guard, given the maximum distance that the beam can travel.

   The room has integer dimensions [1 < x_dim <= 1250, 1 < y_dim <= 1250]. You and the elite
   guard are both positioned on the integer lattice at different distinct positions (x, y)
   inside the room such that [0 < x < x_dim, 0 < y < y_dim]. Finally, the maximum distance
   that the beam can travel before becoming harmless will be given as an integer 1 < distance
   <= 10000.

   For example, if you and the elite guard were positioned in a room with dimensions [3, 2],
   your_position [1, 1], guard_position [2, 1], and a maximum shot distance of 4, you could
   shoot in seven different directions to hit the elite guard (given as vector bearings from
   your location): [1, 0], [1, 2], [1, -2], [3, 2], [3, -2], [-3, 2], and [-3, -2]. As specific
   examples, the shot at bearing [1, 0] is the straight line horizontal shot of distance 1,
   the shot at bearing [-3, -2] bounces off the left wall and then the bottom wall before
   hitting the elite guard with a total shot distance of sqrt(13), and the shot at bearing
   [1, 2] bounces off just the top wall before hitting the elite guard with a total shot
   distance of sqrt(5).
   */

/* IDEA
 *
 * When we shoot and it bounces off of a wall, it's the same as a continued line, but in a
 * mirrored room
 *
 * ex. if we are x and we shoot into the corner to hit ourself:
 * _____
 * |../|
 * |.x.|
 * |...|
 * -----
 * It's the same as this:
 * ________
 * |......|
 * |....x.|
 * |.../..|
 * |../...|
 * |.x....|
 * |......|
 * --------
 *
 * The distance between bouncing off the corner and hitting ourselves is the same as shooting
 * directly to our mirrored self. So, all we have to do is continuously mirror our board and
 * try shooting at the guard until the distance from our point to the guard is too far away,
 * then we count how many of those don't result in us getting hit first
 */

/* UPDATES
 * Submission 1 failed because of stack overflow
 * Submission 2 failed because I forgot to import libraries
 * Submission 3 failed because of a typo
 * Submission 4 probably failed because of TLE
 * ...a crap ton of other submissions that failed
 *  (but now I know that Submission 4 most likely wasn't TLE)
 * Stopped couting submissions - YES I FINALLY GOT IT - timestamp: 1:48am
 */

import java.util.TreeSet;
import java.util.TreeMap;
import java.util.Map;
import java.util.LinkedList;
import java.util.Queue;
import java.lang.Math;

class gun {
    public static void main(String[] args) {
        int dim[]=new int[]{10,10};
        int yp[]=new int[]{4,4};
        int gp[]=new int[]{3,3};
        System.out.println(solution(dim, yp, gp, 5000));
        dim=new int[]{3,2};
        yp=new int[]{1,1};
        gp=new int[]{2,1};
        //System.out.println(solution(dim, yp, gp, 4));
    }

    static TreeSet<Cell> pts=new TreeSet<Cell>();
    static TreeMap<pii, Cell> angles1=new TreeMap<pii, Cell>();
    static TreeMap<pii, Cell> angles2=new TreeMap<pii, Cell>();
    static int or, ot, ox, oy, od;

    public static int solution(int[] dimensions, int[] your_position, int[] guard_position, int distance) {
        ot=dimensions[1];
        or=dimensions[0];
        ox=your_position[0];
        oy=your_position[1];
        od=distance;
        Cell start=new Cell(ox, oy, guard_position[0], guard_position[1], 0, 0);
        pts.add(start);
        mirror(start);
        for (Cell cur:pts) { //Goes through all points (cells) and puts them in a TreeMap based of (pii of vector slope, Cell) to keep
            if (get_dist(cur)>od*od) //track of individual shooting angles from your current position to every other guard
                continue;
            int GCD=gcd((oy-cur.gy), (ox-cur.gx));
            pii p=new pii((oy-cur.gy)/GCD, (ox-cur.gx)/GCD);
            if (!angles1.containsKey(p)) //If we haven't seen this angle yet, add it to the map
                angles1.put(p, cur);
            else { //Otherwise, update if the distance to the new point is less than the one in the map
                Cell c=angles1.get(p);
                int dist1=(c.gx-ox)*(c.gx-ox)+(c.gy-oy)*(c.gy-oy);
                int dist2=(cur.gx-ox)*(cur.gx-ox)+(cur.gy-oy)*(cur.gy-oy);
                if (dist2<dist1) {
                    angles1.remove(p);
                    angles1.put(p, cur);
                }
            }
            if (cur.cy==oy && cur.cx==ox)
                continue;
            GCD=gcd((oy-cur.cy), (ox-cur.cx)); //Same thing here but for your positions (to check for hitting yourself before the guard)
            p=new pii((oy-cur.cy)/GCD, (ox-cur.cx)/GCD);
            if (!angles2.containsKey(p))
                angles2.put(p, cur);
            else {
                Cell c=angles2.get(p);
                int dist1=(c.cx-ox)*(c.cx-ox)+(c.cy-oy)*(c.cy-oy);
                int dist2=(cur.cx-ox)*(cur.cx-ox)+(cur.cy-oy)*(cur.cy-oy);
                if (dist2<dist1) {
                    angles2.remove(p);
                    angles2.put(p, cur);
                }
            }
        }
        int ans=0;
        for (Map.Entry<pii, Cell> entry:angles1.entrySet()) { //Goes through all guards and checks if the angle to hit this guard is also
            pii p=new pii(entry.getKey());                    //an angle to hit yourself. If it is, then check if you're closing or the
            if (angles2.containsKey(p)) {                     //guard. If the guard is closer, or if this angle is guaranteed to not hit
                Cell cur=new Cell(entry.getValue());          //you, increment the answer
                Cell c=new Cell(angles2.get(p));
                int dist1=(c.cx-ox)*(c.cx-ox)+(c.cy-oy)*(c.cy-oy);
                int dist2=(cur.cx-ox)*(cur.cx-ox)+(cur.cy-oy)*(cur.cy-oy);
                if (dist2<dist1 && dist1>0)
                    ++ans;
            }
            else
                ++ans;
        }
        return ans;
    }

    static int gcd(int a, int b) { //GCD function for keeping track of the vector bearings (added when I decided to stop using arctan)
        if (a<0)
            a*=-1;
        if (b<0)
            b*=-1;
        if (b==0)
            return a;
        return gcd(b, a%b);
    }

    static public class pii implements Comparable<pii> { //pair<int, int> for Java, to hold relative vector bearings of positions in
        public int a;                                    //other cells to your original position - probably an unnecessary switch but
        public int b;                                    //at the time of doing the problem I kept getting one testcase wrong and I
                                                         //didn't know if it was because of double's precision when I was using arctan
        public pii(int a, int b) {                       //to find angles (in the end, it was because I wasn't expanding out enough
            this.a=a;                                    //when mirroring
            this.b=b;
        }
        public pii(pii p) {
            this.a=p.a;
            this.b=p.b;
        }
        public int compareTo(pii p) {
            if (a<p.a)
                return -1;
            if (a>p.a)
                return 1;
            if (b<p.b)
                return -1;
            if (b>p.b)
                return 1;
            return 0;
        }
    }

    static public class Cell implements Comparable<Cell> { //Cell class - has x- and y-ids to tell you which cell you're at relative to
        public int idx;                                    //your starting cell (0, 0), and holds the position of yourself and the guard
        public int idy;                                    //in each of those cells

        public int cx;
        public int cy;
        public int gx;
        public int gy;

        public Cell() {}
        public Cell(Cell a) {
            this.cx=a.cx;
            this.cy=a.cy;
            this.gx=a.gx;
            this.gy=a.gy;
            this.idx=a.idx;
            this.idy=a.idy;
        }
        public Cell(int x1, int y1, int x2, int y2, int idx, int idy) {
            this.cx=x1;
            this.cy=y1;
            this.gx=x2;
            this.gy=y2;
            this.idx=idx;
            this.idy=idy;
        }
        public int compareTo(Cell p) {
            if (idx<p.idx)
                return -1;
            if (idx>p.idx)
                return 1;
            if (idy<p.idy)
                return -1;
            if (idy>p.idy)
                return 1;
            return 0;
        }
    }

    static int get_dist(Cell a) { //Gets distance between a cell's guard position and your original position
        return (a.gy-oy)*(a.gy-oy)+(a.gx-ox)*(a.gx-ox);
    }

    static Cell incr(int dir, Cell c) { //Increments cell in specified direction and updates its positional contents
        int ky[]=new int[]{0,1,0,-1};
        int kx[]=new int[]{1,0,-1,0};
        Cell nxt=new Cell(c);
        nxt.idx+=kx[dir];
        nxt.idy+=ky[dir];
        int cl=or*c.idx;
        int cr=or+or*c.idx;
        int ct=ot+ot*c.idy;
        int cb=ot*c.idy;
        if (dir==0) {
            nxt.cx=2*cr-c.cx;
            nxt.gx=2*cr-c.gx;
        }
        if (dir==1) {
            nxt.cy=2*ct-c.cy;
            nxt.gy=2*ct-c.gy;
        }
        if (dir==2) {
            nxt.cx=2*cl-c.cx;
            nxt.gx=2*cl-c.gx;
        }
        if (dir==3) {
            nxt.cy=2*cb-c.cy;
            nxt.gy=2*cb-c.gy;
        }
        return nxt;
    }

    public static void mirror(Cell st) { //Mirrors cells for all possible reachable values and inserts them into pts TreeSet
        int xmax=od/or+1;                //There are definitely more efficient ways of doing this (realizing that it's symmetrical
        int ymax=od/ot+1;                //in all four directions) but this runs in time and works and is easier to read so whatever
        int i=0;
        for (Cell cur=new Cell(st); i<=xmax; cur=incr(0, cur), ++i) {
            int j=0;
            for (Cell c=new Cell(cur); j<=ymax; c=incr(1, c), ++j)
                if (!pts.contains(c))
                    pts.add(c);
            j=0;
            for (Cell c=new Cell(cur); j<=ymax; c=incr(3, c), ++j)
                if (!pts.contains(c))
                    pts.add(c);
        }
        i=0;
        for (Cell cur=new Cell(st); i<=xmax; cur=incr(2, cur), ++i) {
            int j=0;
            for (Cell c=new Cell(cur); j<=ymax; c=incr(1, c), ++j)
                if (!pts.contains(c))
                    pts.add(c);
            j=0;
            for (Cell c=new Cell(cur); j<=ymax; c=incr(3, c), ++j)
                if (!pts.contains(c))
                    pts.add(c);
        }
    }
}

