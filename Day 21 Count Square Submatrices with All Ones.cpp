PROBLEM:



Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.


Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.

Example 2:
Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1. 1 <= arr.length <= 300
2. 1 <= arr[0].length <= 300
3. 0 <= arr[i][j] <= 1




SOLUTION:



class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int i,j,n,m,ans=0;
        n=matrix.size();
        m=matrix[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {   
               if( (i==0 || j==0 ) && matrix[i][j]==1)
                   dp[i][j]=1;
                else if(matrix[i][j]==1)
                    dp[i][j] = 1 +min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                
                ans+=dp[i][j];
            }
        }
        
        return ans;
        
    }
};
