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
    void preorder(TreeNode* head, TreeNode* &tail)
    {
        if(!head) return;
            
        tail->right=head;
        TreeNode* l = head->left;
        TreeNode* r = head->right;
        tail=tail->right;
        tail->right = NULL;
        head->left = NULL;


        if(l) preorder(l, tail);
        if(r) preorder(r, tail);

        return;

    }

    void flatten(TreeNode* root) {
        TreeNode* head = root;
        TreeNode* tail = new TreeNode(-1);
        preorder(head, tail);

        tail = root;



        return ;
    }
};