/* 
 * GOOGLE FOOBAR - LVL 2 - ion-flux-relabeling 
 * 
 * Basically you gotta find the parent of each number on a binary tree sort of thing
 * 
 * ex: 2 -> 3, 14 -> 15, 22 -> 30
 *                     31
 *        15                        30
 *    7        14           22             29
 *  3   6   10    13     18     21     25     28
 * 1 2 4 5 8  9 11  12 16  17 19  20 23  24 26  27
 * 
 * So the idea was that there are two positions in the base: pos 1 (left)
 * and pos 2 (right)
 * 
 * From pos 1, to get the top number, do the # + 2^row number
 * From pos 2, do # + 1
 * 
*/

import java.lang.Math;

public class ion {
	public static void main(String[] args) { // to test
        //System.out.print(whichRow(15, 4));
		//System.out.println(posOne(7, 4));
		int[] temp = {29, 10, 31};
		int[] answer = new int[3];
		answer = solution(5, temp);
		for (int i = 0; i < 3; i++) System.out.println(answer[i]);
    }
	
	public static int[] solution(int h, int[] q) {
        int size = q.length;
        int[] p = new int[size];
        
        int Row;
        
        for (int i = 0; i < size; i++) {
            Row = whichRow(q[i], h) + 1;
            
            if (posOne(q[i], h) == true)
            	p[i] = q[i] + (int) Math.pow(2, Row);
            else p[i] = q[i] + 1;
            
            if (p[i] > (int) Math.pow(2, h) - 1) p[i] = -1;
            //System.out.println(p[i]);
        }
        return p;
        
    }
    
    static int whichRow(int a, int height) {//Counts rows: 1 1 2 1 1 2 3 1 1 2 1 1 2 3 4 ...
        int rowcounter = 0;                 //Some random algorithm counts the row
        int[] rowcount = new int[height];   //(rowcounter) and how many times it has
        for (int i = 0; i < a; i++) {       //counted each row (an array called
        	rowcount[rowcounter] += 1;      //rowcounter)
        	//System.out.println(rowcounter + " " + rowcount[rowcounter]);
        	if (rowcount[rowcounter] == 2 && i != (a-1)) {
        		rowcount[rowcounter] = 0;
        		rowcounter++;
        	}
        	else if (rowcounter > 0 && i != (a-1)) {
        		rowcounter = 0;
        	}
        }
        return rowcounter;
    }
    
    static boolean posOne(int a, int height) { //Uses the same counting technique as
    	boolean yes = true;                    //the previous one, except this time
    										   //we're looking for the position, not
    	int rowcounter = 0;                    //the row
        int[] rowcount = new int[height];
        for (int i = 0; i < a; i++) {
        	rowcount[rowcounter] += 1;
        	//System.out.println(rowcounter + " " + rowcount[rowcounter]);
        	if (rowcount[rowcounter] == 2 && i != (a-1)) {
        		rowcount[rowcounter] = 0;
        		rowcounter++;
        	}
        	else if (rowcounter > 0 && i != (a-1)) {
        		rowcounter = 0;
        	}
        }
        //System.out.println(rowcount[rowcounter]);
        if (rowcount[rowcounter] == 2) yes = false;
    	
    	return yes;
    }

}

