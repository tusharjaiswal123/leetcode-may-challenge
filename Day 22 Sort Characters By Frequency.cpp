PROBLEM:


Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:
Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:
Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.




SOLUTION:



unordered_map<char,int> m;

class Solution {
public:

    bool static cmp(char a,char b)
    {
        return (m[a]>m[b] || (m[a]==m[b] && a<b));
    }
    
    string frequencySort(string s) {
        
        int i,n;
        n=s.length();
        m.clear();
        
        for(i=0;i<n;i++)
        {
            m[s[i]]++;
        }
        
        // for(auto k:m)
        // {
        //     cout<<k.first<<" "<<k.second<<endl;
        // }
        
        sort(s.begin(),s.end(),cmp);
       
    
        
        return s;
    }
};
