/* PROBLEM STATEMENT
There's some unrest in the minion ranks: minions with ID numbers
like "1", "42", and other "good" numbers have been lording it over
the poor minions who are stuck with more boring IDs. To quell the
unrest, Commander Lambda has tasked you with reassigning everyone
new, random IDs based on her Completely Foolproof Scheme.

She's concatenated the prime numbers in a single long string:
"2357111317192329...". Now every minion must draw a number from a
hat. That number is the starting index in that string of primes, and
the minion's new ID number will be the next five digits in the string.
So if a minion draws "3", their ID number will be "71113".

Help the Commander assign these IDs by writing a function answer(n)
which takes in the starting index n of Lambda's string of all primes,
and returns the next five digits in the string. Commander Lambda has a
lot of minions, so the value of n will always be between 0 and 10000.
*/

class primes {
    public static void main(String[] args) {
        System.out.println(solution(3));
    }

    public static String solution(int x) {
        String ans=""; int cur=2;
        while (ans.length()<1e4) {
            boolean f=true;
            for (int i=2; i*i<=cur; ++i)
                if (cur%i==0) {
                    f=false;
                    break;
                }
            if (f==true)
                ans+=String.valueOf(cur);
            ++cur;
        }
        return ans.substring(x, x+5);
    }
}

