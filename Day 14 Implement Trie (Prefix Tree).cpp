PROBLEM:

Implement a trie with insert, search, and startsWith methods.

Example:
Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:
You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.



SOLUTION:


class Trie {
    private:
    unordered_set<string> s,s1; 
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        s.insert(word);
        
        string m="";
        for(int i=0;i<word.size();i++)
        {
            m+=word[i];
            s1.insert(m);
        }
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        if(s.find(word)!=s.end())
            return true;
        else
            return false;
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        if(s1.find(prefix)!=s1.end())
            return true;
        else
            return false;
        
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
