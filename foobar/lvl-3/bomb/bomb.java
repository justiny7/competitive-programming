//Kinda like finding the GCD of the two except keeping track of # of subtractions
//Yay worked first try except I spend like a hour coding the bignum class T-T

/* Problem statement:
   Bomb, Baby!
   ===========

   You're so close to destroying the LAMBCHOP doomsday device you can taste it! But in order to do so, you need
   to deploy special self-replicating bombs designed for you by the brightest scientists on Bunny Planet. There
   are two types: Mach bombs (M) and Facula bombs (F). The bombs, once released into the LAMBCHOP's inner workings,
   will automatically deploy to all the strategic points you've identified and destroy them at the same time.

   But there's a few catches. First, the bombs self-replicate via one of two distinct processes:
   Every Mach bomb retrieves a sync unit from a Facula bomb; for every Mach bomb, a Facula bomb is created;
   Every Facula bomb spontaneously creates a Mach bomb.

   For example, if you had 3 Mach bombs and 2 Facula bombs, they could either produce 3 Mach bombs and 5 Facula bombs,
   or 5 Mach bombs and 2 Facula bombs. The replication process can be changed each cycle.

   Second, you need to ensure that you have exactly the right number of Mach and Facula bombs to destroy the LAMBCHOP
   device. Too few, and the device might survive. Too many, and you might overload the mass capacitors and create a
   singularity at the heart of the space station - not good!

   And finally, you were only able to smuggle one of each type of bomb - one Mach, one Facula - aboard the ship when
   you arrived, so that's all you have to start with. (Thus it may be impossible to deploy the bombs to destroy the
   LAMBCHOP, but that's not going to stop you from trying!)

   You need to know how many replication cycles (generations) it will take to generate the correct amount of bombs
   to destroy the LAMBCHOP. Write a function solution(M, F) where M and F are the number of Mach and Facula bombs needed.
   Return the fewest number of generations (as a string) that need to pass before you'll have the exact number of bombs
   necessary to destroy the LAMBCHOP, or the string "impossible" if this can't be done! M and F will be string
   representations of positive integers no larger than 10^50. For example, if M = "2" and F = "1", one generation would
   need to pass, so the solution would be "1". However, if M = "2" and F = "4", it would not be possible.
*/

class bomb {
    public static void main(String[] args) {
        System.out.println(solution("16", "7"));
    }

    public static String solution(String x, String y) {
        bignum a=new bignum(x);
        bignum b=new bignum(y);
        bignum ans=new bignum();
        while (!(is(a, 1) && is(b, 1))) {
            if (is(a, 0) || is(b, 0))
                return "impossible";
            if (is(b, 1)) {
                ans=add(ans, decr(a));
                break;
            }
            if (is(a, 1)) {
                ans=add(ans, decr(b));
                break;
            }
            bignum f=first_smaller_mult(b, a);
            ans=add(ans, f);
            bignum c=mult(f, b);
            bignum b2=b;
            b=sub(a, c);
            a=b2;
        }
        String ans_s="";
        for (int i=ans.len-1; i>=0; --i)
            ans_s+=Integer.toString(ans.num[i]);
        return ans_s;
    }

    public static class bignum {
        public int num[]=new int[201];
        public int len, sign;
        public bignum() {
            len=1;
            sign=0;
        }
        public bignum(String x) {
            len=x.length();
            for (int i=len-1; i>=0; --i)
                num[len-i-1]=Character.getNumericValue(x.charAt(i));
        }
    }

    static boolean is(bignum a, int x) {
        return (a.len==1 && a.num[0]==x);
    }

    static int compare(bignum a, bignum b) {
        if (a.len>b.len)
            return 1;
        if (a.len<b.len)
            return 0;
        for (int i=a.len-1; i>=0; --i) {
            if (a.num[i]>b.num[i])
                return 1;
            if (a.num[i]<b.num[i])
                return 0;
        }
        return 2;
    }

    static bignum add(bignum a, bignum b) {
        bignum ans=new bignum();
        int l=Math.max(a.len, b.len), carry=0;
        for (int i=0; i<l; ++i) {
            ans.num[i]=a.num[i]+b.num[i]+carry;
            carry=ans.num[i]/10;
            ans.num[i]%=10;
        }
        ans.len=l;
        if (carry>0) {
            ++ans.len;
            ans.num[l]=carry;
        }
        return ans;
    }

    static bignum sub(bignum a, bignum b) {
        bignum ans=new bignum();
        int l=Math.max(a.len, b.len), borrow=0;
        for (int i=0; i<l; ++i) {
            ans.num[i]=a.num[i]-b.num[i]-borrow;
            borrow=0;
            if (ans.num[i]<0) {
                borrow=1;
                ans.num[i]+=10;
            }
            if (ans.num[i]>0)
                ans.len=i+1;
        }
        return ans;
    }

    static bignum mult_and_add(bignum a, int s, int off) {
        bignum ans=new bignum();
        int carry=0;
        int i=0;
        for (; i<a.len; ++i) {
            ans.num[i+off]=a.num[i]*s+carry;
            carry=ans.num[i+off]/10;
            ans.num[i+off]%=10;
        }
        i=a.len;
        while (carry>0) {
            ans.num[i+off]=carry%10;
            carry/=10;
            ++i;
        }
        ans.len=i+off;
        return ans;
    }

    static bignum mult(bignum a, bignum b) {
        bignum ans=new bignum();
        int off=0;
        for (int i=0; i<a.len; ++i) {
            ans=add(ans, mult_and_add(b, a.num[i], off));
            ++off;
        }
        return ans;
    }

    static bignum scalar_div(bignum a, int s) {
        bignum ans=new bignum();
        int rem=0;
        for (int i=a.len-1; i>=0; --i) {
            rem=rem*10+a.num[i];
            ans.num[i]=rem/s;
            if (ans.num[i]>0 && i+1>ans.len)
                ans.len=i+1;
            rem%=s;
        }
        return ans;
    }

    static bignum decr(bignum a) {
        bignum ans=new bignum();
        int l=a.len, borrow=1;
        for (int i=0; i<l; ++i) {
            ans.num[i]=a.num[i]-borrow;
            borrow=0;
            if (ans.num[i]<0) {
                ans.num[i]+=10;
                borrow=1;
            }
            if (ans.num[i]>0)
                ans.len=i+1;
        }
        return ans;
    }

    static bignum incr(bignum a) {
        bignum ans=new bignum();
        int l=a.len, carry=1;
        for (int i=0; i<l; ++i) {
            ans.num[i]=a.num[i]+carry;
            carry=ans.num[i]/10;
            ans.num[i]%=10;
        }
        ans.len=l;
        if (carry>0) {
            ++ans.len;
            ans.num[l]=carry;
        }
        return ans;
    }

    static void print(bignum a) {
        for (int i=a.len-1; i>=0; --i)
            System.out.print(a.num[i]);
        System.out.println();
    }

    static bignum first_smaller_mult(bignum a, bignum b) { //binary search for first multiple of a smaller than b
        bignum lo=new bignum("0");
        bignum hi=b;
        while (compare(lo, hi)==0) {
            bignum mid=scalar_div(incr(add(lo, hi)), 2);
            if (compare(mult(mid, a), b)!=1)
                lo=mid;
            else
                hi=decr(mid);
        }
        return lo;
    }
}

