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
    void helper(int start, int end,TreeNode* node, vector<int> &nums,bool l)
    {
        if(end<start) return;
        if(start==end)
        {
            if(l)
            {
                node->right=new TreeNode(nums[start]);
            }
            else
            {
                node->left= new TreeNode(nums[start]);
            }
            return;
        }
        int mid = (start+end)/2;
        if(l)
        {
            node->right=new TreeNode(nums[mid]);
            node = node ->right;
        }
        else
        {
            node->left= new TreeNode(nums[mid]);
            node = node ->left;
        }
        //cout<<start<<" "<<mid<<" "<<end<<endl;
        helper(start,mid-1,node,nums,0);
        helper(mid+1,end,node,nums,1);
        return;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return NULL;
        int l = nums.size();
        int mid;
        mid=(l/2);
        TreeNode *root = new TreeNode(nums[mid]);
        helper(0,mid-1,root,nums,0);
        helper(mid+1,nums.size()-1,root,nums,1);
        return root;
    }
};