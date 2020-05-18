PROBLEM:


Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the
first string's permutations is the substring of the second string.

 
Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False
 
Note:

1.The input strings only contain lower case letters.
2.The length of both given strings is in range [1, 10,000].



SOLUTION:



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> a(26,0);     //Sliding Window
        vector<int> b(26,0);
        
        int i,n1,n2;
        n1=s1.length();
        n2=s2.length();
        
        if(n1>n2)
            return false;
        
        for(i=0;i<n1;i++)
        {
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        
        if(a==b)
            return true;
        
        int p;
        p=0;
        for(i=n1;i<n2;i++)
        {
            b[s2[p]-'a']--;
            b[s2[i]-'a']++;
            p++;
            
            if(a==b)
                return true;
        }
        
        return false;
        
    }
};
