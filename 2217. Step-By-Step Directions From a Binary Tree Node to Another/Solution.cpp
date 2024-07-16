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
    TreeNode* lca(TreeNode* root, int startValue, int destValue)
    {
        if (root==NULL)return NULL;
        if(root->val==startValue||root->val==destValue) return root;
        TreeNode *l=lca(root->left,startValue,destValue);
        TreeNode* r=lca(root->right,startValue,destValue);
        if(l&&r)
        {
            return root;
        }
        if(l)
        {
            return l;
        }
        else{
            return r;
        }
    }

    bool findPath(TreeNode* root, int value, string &path) {
    if (root == nullptr) return false;
    if (root->val == value) return true;
    
    path.push_back('L');
    if (findPath(root->left, value, path)) return true;
    path.pop_back();
    
    path.push_back('R');
    if (findPath(root->right, value, path)) return true;
    path.pop_back();
    
    return false;
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* l = lca(root,startValue,destValue);
        cout<<l->val<<endl;
        string s,d;
        TreeNode* temp=l;
        findPath(l,startValue,s);
        findPath(temp,destValue,d);
        //cout<<s<<" "<<d<<endl;
        for(int i=0;i<s.size();i++)
        {
            s[i]='U';
        }
        return s+d;
    }
};