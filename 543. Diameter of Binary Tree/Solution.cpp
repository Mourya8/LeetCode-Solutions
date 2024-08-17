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
    int traverse(TreeNode* root,int &d)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=traverse(root->left,d);
        int r=traverse(root->right,d);
        d=max(d,l+r+1);
        return max(l,r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=1;
        traverse(root,d);
        return d-1;
    }
};