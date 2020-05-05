PROBLEM:


Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.


SOLUTION:


class Solution {
public:
    int firstUniqChar(string s) {
        
        int n,i;
        n=s.length();
        
        int a[26]={0};
        
        for(i=0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        
        for(i=0;i<n;i++)
        {
            if(a[s[i]-'a']==1)
            {
                return i;
            }
        }
        
        return -1;
        
    }
};
