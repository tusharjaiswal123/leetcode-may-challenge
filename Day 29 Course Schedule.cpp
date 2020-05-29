PROBLEM:




There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
 

Constraints:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
1. 1 <= numCourses <= 10^5





SOLUTION:


//Detect cycle in directed graph(using dfs/kahn's algo)



class Solution {
public:
    
    bool dfs(vector<int> adj[],vector<bool>& vis,vector<bool>& ancestor,int s)
    {
        vis[s]=true;
        ancestor[s]=true;
        
        for(auto k:adj[s])
        {
            if(!vis[k])
            {
                if(dfs(adj,vis,ancestor,k))
                    return true;
            }
            
            else if(vis[k]==true && ancestor[k]==true)
                return true;
        }
        
        ancestor[s]=false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int i,n,a,b;
        vector<int> adj[numCourses];
        vector<bool> vis(numCourses,false);
        vector<bool> ancestor(numCourses,false);
        
        n=prerequisites.size();
        
        for(i=0;i<n;i++)
        {
            a=prerequisites[i][0];
            b=prerequisites[i][1];
            
            adj[b].push_back(a);
        }
        
        for(i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(adj,vis,ancestor,i))
                    return false;
            }
        }
        
        return true;
        
        
    }
};
