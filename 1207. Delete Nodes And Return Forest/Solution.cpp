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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        map<int,int> m;
        vector<TreeNode*> r;
        queue <TreeNode*> q;
        for(int i=0;i<to_delete.size();i++)
        {
            m[to_delete[i]]=1;
        }
        if(m.find(root->val)==m.end()) r.push_back(root);

        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp= q.front();
            q.pop();
            if(m.find(temp->val)!=m.end())
            {
                if(temp->left)
                {
                    if(m.find(temp->left->val)==m.end()) r.push_back(temp->left);
                }
                if(temp->right)
                {
                    if(m.find(temp->right->val)==m.end()) r.push_back(temp->right);
                }
            }
            if(temp->left)
            {
                q.push(temp->left);
               if(m.find(temp->left->val)!=m.end()) temp->left=NULL;
            }
            if(temp->right)
            {
                q.push(temp->right);
               if(m.find(temp->right->val)!=m.end()) temp->right=NULL;
            }
        }
        return r;
    }
};