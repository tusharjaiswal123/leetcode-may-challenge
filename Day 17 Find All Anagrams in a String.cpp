PROBLEM:



Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.

Example 1:
Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".




SOLUTION:


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int i,j,n1,n2,f;
        n1=s.size();
        n2=p.size();
        
        vector<int> p_map(26,0),s_map(26,0);
        vector<int> v;
        
        if(n2>n1)
            return v;
        
        for(i=0;i<n2;i++)
        {
            p_map[p[i]-'a']++;
            s_map[s[i]-'a']++;
        }
        
        if(p_map==s_map)                     //Sliding Window
            v.push_back(0);
        
        j=1;
        
        for(i=n2;i<n1;i++)
        {   
            s_map[s[i-n2]-'a']--;
            s_map[s[i]-'a']++;
            
            if(s_map==p_map)
                v.push_back(j);
            
            j++;
        }
        
        return v;
    }
};
