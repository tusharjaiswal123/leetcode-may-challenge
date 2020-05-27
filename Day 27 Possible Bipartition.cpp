PROBLEM:




Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.


Example 1:
Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]

Example 2:
Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

Example 3:
Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
 

Note:

1. 1 <= N <= 2000
2. 0 <= dislikes.length <= 10000
3. 1 <= dislikes[i][j] <= N
4. dislikes[i][0] < dislikes[i][1]
5. There does not exist i != j for which dislikes[i] == dislikes[j].





SOLUTION:



class Solution {
public:
    
    bool dfs(vector<int> adj[],vector<bool>& vis,int color[],int s)
    {
        vis[s]=true;
        
        for(auto k:adj[s])
        {
            if(!vis[k])
            {
                color[k]=1-color[s];
                
                if(dfs(adj,vis,color,k)==false)
                return false;
            
            }
            else if(color[k]==color[s])
                return false;
        }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        int n,m,i,j,a,b;
        n=dislikes.size();
        
        vector<int> adj[N+1];
        vector<bool> vis(N+1,false);
        int color[N+1];
        
        for(i=0;i<n;i++)
        {
            a=dislikes[i][0];
            b=dislikes[i][1];
            
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        for(i=1;i<=N;i++)
        {
            if(!vis[i])
            {   
                color[i]=0;
                if(dfs(adj,vis,color,i)==false)
                    return false;
            }
        }
        
        
        return true;
        
    }
};
