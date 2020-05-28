PROBLEM:


Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their
binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]

Follow up:

1. It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time
O(n) /possibly in a single pass?
2. Space complexity should be O(n).
3. Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.




SOLUTION:



class Solution {
public:
    vector<int> countBits(int num) {
        
        int i;
        
        vector<int> v;
        
        for(i=0;i<=num;i++)
        {
            v.push_back(__builtin_popcount(i));
        }
            
        
        return v;
    }
};class Solution {
public:
    vector<int> countBits(int num) {
        
        int i;
        
        vector<int> v;
        
        for(i=0;i<=num;i++)
        {
            v.push_back(__builtin_popcount(i));
        }
            
        
        return v;
    }
};
