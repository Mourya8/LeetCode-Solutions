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
    void helper(TreeNode* p, TreeNode* q, bool & b)
    {
        if(p!=NULL&&q!=NULL)
        {
            if(p->val!=q->val) 
            {
                b =0;
                return;
            }
            helper(p->left,q->left,b);
            helper(p->right,q->right,b);
        }
        else if((p==NULL && q!=NULL) || (p!=NULL && q==NULL))
        {
            b = 0;
            return;
        }
        return;


    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool b =1;
        helper(p,q,b);
        return b;
    }
};