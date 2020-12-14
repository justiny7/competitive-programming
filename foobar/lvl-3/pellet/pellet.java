/*
 * Google foobar Level 3 Problem 1
 *
 * Question:
 * Given a number x represented by a string of up to 309 digits, you can either
 * add 1 to the number, subtract 1 from the number, or divide the number by 2 if
 * it's divisible by 2. What is the minimum number of moves to make the number 1?
 *
 * Solution:
 * If the number is divisible by 2, it's always optimal to divide it by 2, as, in
 * one move, dividing always decreases your number by either more than or equal to
 * subtracting. If the number is odd, then you have to figure out whether it's more
 * optimal to add 1 or subtract 1. Now, if the number is divisible by 4, then it can
 * be divided twice in succession. Therefore, in the case that the number is odd, we
 * should always greedily choose the operation that makes it divisible by 4. So, if
 * the number%4 is 1, then subtract 1; otherwise (number%4 is 3), add 1. The exception
 * is if the number is 3 - in that case, it's more optimal to subtract.
 *
 * Note: we have to use bignums in order to store the number
 *
*/

public class pellet {
    public static void main(String[] args) {
        System.out.println(solution("2048"));
    }

    public static int solution(String x) {
        int ans=0;
        bignum cur=new bignum(x);
        while (!(cur.len==1 && cur.num[0]==1)) {
            if (cur.num[0]%2==0)
                cur=div(cur);
            else if ((cur.len==1 && cur.num[0]==3) ||
                    ((10*cur.num[1]+cur.num[0])%4)==1)
                cur=sub(cur);
            else
                cur=add(cur);
            ++ans;
        }
        return ans;
    }

    public static class bignum {
        public int num[]=new int[310];
        public int len;
        public bignum() {
            len=1;
        }
        public bignum(String x) {
            len=x.length();
            for (int i=len-1; i>=0; --i)
                num[len-i-1]=Character.getNumericValue(x.charAt(i));
        }
    }
    static bignum add(bignum a) {
        bignum ans=new bignum();
        int l=a.len, carry=1;
        for (int i=0; i<l; ++i) {
            ans.num[i]=a.num[i]+carry;
            carry=ans.num[i]/10;
            ans.num[i]%=10;
        }
        if (carry>0) {
            ans.num[l]=carry;
            ans.len=l+1;
        }
        else
            ans.len=l;
        return ans;
    }
    static bignum sub(bignum a) {
        bignum ans=new bignum();
        int l=a.len, borrow=1;
        for (int i=0; i<l; ++i) {
            ans.num[i]=a.num[i]-borrow;
            if (ans.num[i]<0) {
                ans.num[i]+=10;
                borrow=1;
            }
            else
                borrow=0;
            if (ans.num[i]>0)
                ans.len=i+1;
        }
        return ans;
    }
    static bignum div(bignum a) {
        bignum ans=new bignum();
        int l=1, rem=0;
        for (int i=a.len-1; i>=0; --i) {
            rem=rem*10+a.num[i];
            ans.num[i]=rem/2;
            if (ans.num[i]>0 && i+1>ans.len)
                ans.len=i+1;
            rem%=2;
        }
        return ans;
    }
}
