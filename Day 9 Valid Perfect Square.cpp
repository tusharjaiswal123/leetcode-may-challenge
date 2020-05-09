PROBLEM:


Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false



SOLUTION:


class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long i,a,b;
        
        for(i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                a=num/i;
                b=i;
                
                if(a==b)
                    return true;
            }
        }
        
        return false;
    }
};
