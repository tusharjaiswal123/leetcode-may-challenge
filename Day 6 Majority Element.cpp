PROBLEM:


Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2



SOLUTION:


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int i,n,k;
        n=nums.size();
        k=n/2;
        
        unordered_map<int,int> m;
        
        for(i=0;i<n;i++)
        {
            m[nums[i]]++;
            
            if(m[nums[i]]>k)
                return nums[i];
        }
        
        return -1;
    }
};
