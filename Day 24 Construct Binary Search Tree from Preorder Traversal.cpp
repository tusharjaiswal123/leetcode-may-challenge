PROBLEM:



Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val,
and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the
node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]




SOLUTION:



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return bst(preorder,INT_MAX,i);
        
    }
    
    TreeNode* bst(vector<int>& preorder,int upper,int &i)
    {
        if(i==preorder.size() || preorder[i] > upper)
            return NULL;
        
        TreeNode* newnode = new TreeNode(preorder[i]);
        i++;
        newnode->left = bst(preorder,newnode->val,i);
        newnode->right = bst(preorder,upper,i);
        
        return newnode;
    }
};
