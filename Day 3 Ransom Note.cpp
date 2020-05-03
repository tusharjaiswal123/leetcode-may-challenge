PROBLEM:


Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that
will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true


SOLUTION:


class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int i,n1,n2;
        n1=ransomNote.length();
        n2=magazine.length();
        
        if(n1>n2)
            return false;
        
        unordered_map<char,int> m;
        
        for(i=0;i<n2;i++)
        {
            m[magazine[i]]++;
        }
        
        for(i=0;i<n1;i++)
        {
            if(m[ransomNote[i]]>0)
            {
                m[ransomNote[i]]--;
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
};
