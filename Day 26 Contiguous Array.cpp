PROBLEM:



Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.




SOLUTION:



class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        int i,n,ans=0,sum=0;
        n=nums.size();
        unordered_map<int,int> m;
        
        m[0]=-1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
                sum--;
            else
                sum++;
            
            if(m.find(sum)!=m.end())
                ans=max(ans,i-m[sum]);
            else
                m[sum]=i;
        }
        
        return ans;
        
    }
};
