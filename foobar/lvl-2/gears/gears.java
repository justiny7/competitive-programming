/* PROBLEM STATEMENT
   Gearing Up for Destruction
   ==========================

   As Commander Lambda's personal assistant, you've been assigned the task of
   configuring the LAMBCHOP doomsday device's axial orientation gears. It should
   be pretty simple - just add gears to create the appropriate rotation ratio.
   But the problem is, due to the layout of the LAMBCHOP and the complicated
   system of beams and pipes supporting it, the pegs that will support the gears
   are fixed in place.

   The LAMBCHOP's engineers have given you lists identifying the placement of groups
   of pegs along various support beams. You need to place a gear on each peg (otherwise
   the gears will collide with unoccupied pegs). The engineers have plenty of gears in
   all different sizes stocked up, so you can choose gears of any size, from a radius of
   1 on up. Your goal is to build a system where the last gear rotates at twice the rate
   (in revolutions per minute, or rpm) of the first gear, no matter the direction. Each
   gear (except the last) touches and turns the gear on the next peg to the right.

   Given a list of distinct positive integers named pegs representing the location of each
   peg along the support beam, write a function solution(pegs) which, if there is a solution,
   returns a list of two positive integers a and b representing the numerator and denominator
   of the first gear's radius in its simplest form in order to achieve the goal above, such
   that radius = a/b. The ratio a/b should be greater than or equal to 1. Not all support
   configurations will necessarily be capable of creating the proper rotation ratio, so if the
   task is impossible, the function solution(pegs) should return the list [-1, -1].

   For example, if the pegs are placed at [4, 30, 50], then the first gear could have a radius
   of 12, the second gear could have a radius of 14, and the last one a radius of 6. Thus, the
   last gear would rotate twice as fast as the first one. In this case, pegs would be [4, 30, 50]
   and solution(pegs) should return [12, 1].

   The list pegs will be given sorted in ascending order and will contain at least 2 and no more
   than 20 distinct positive integers, all between 1 and 10000 inclusive.
*/

/* SOLUTION
 *
 * The question asks whether, with gears placed on a bar with n pegs at locations given in the (sorted)
 * array pegs, what must the radius of the first gear be if you want the last gear to rotate at 2x the
 * speed of the first so that every gear has at least radius 1? Basically, what radius r would make the
 * last radius r/2. The solution is simple - calculate the distances between each peg and store in array
 * dists. Then, to find the radius of the last gear in relation to r, with some simple math it can be
 * calculated as dists[n-1]-dists[n-2]+dists[n-3]-...-/+dists[1]+/-dists[0]-/+r. Then, if it's a -r in
 * the end, r is (sum of alternating dists)*2/3. Otherwise, it's (sum of alternating dists)*-2. After
 * getting r, make sure for every gear, the radius not less than 1. The answer is returned in the form
 * of ans[0] and ans[1] - the numerator and denominator of the answer, respectively.
 */

public class gears {
	public static int[] Solution(int[] pegs) {
        int ans[] = new int[2];
        int size = pegs.length, den = 1;
        int dists[] = new int[size-1];
        for (int i = 1; i < size; i++)
        	dists[i-1] = pegs[i]-pegs[i-1];
        int buf = 0, mult = 1;
        for (int i = dists.length-1; i >= 0; i--) {
        	buf += mult*dists[i];
        	mult *= -1;
        	//System.out.println(buf);
        }
        if (mult == -1) {
        	buf *= 2;
        	den = 3;
        }
        else
        	buf *= -2;
        //System.out.print(buf + " " + den + "\n");
        int curdist = buf;
        for (int i = 0; i < dists.length; i++) {
        	if (curdist < den) {
        		ans[0] = ans[1] = -1;
        		return ans;
        	}
        	curdist = dists[i]*den-curdist;
        }
    	if (buf%den == 0) {
    		buf /= den;
    		den = 1;
    	}
    	ans[0] = buf;
    	ans[1] = den;
        return ans;
    }
	
	public static void main(String[] args) {
		int test[] = {1, 4, 9, 15};
		int a[] = new int[2];
		a = Solution(test);
		for (int i : a)
			System.out.println(i);
	}

}
