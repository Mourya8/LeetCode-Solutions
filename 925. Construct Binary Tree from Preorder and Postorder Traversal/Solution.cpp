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
    TreeNode* construct(int& preIndex, int postStart, int postEnd, vector<int>& preorder, vector<int>& postorder) {
        if (preIndex >= preorder.size() || postStart > postEnd) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        if (postStart == postEnd) return root; // Leaf node, no children
        
        int leftSubtreeRootIndex = postStart;
        while (postorder[leftSubtreeRootIndex] != preorder[preIndex]) {
            leftSubtreeRootIndex++;
        }
        
        root->left = construct(preIndex, postStart, leftSubtreeRootIndex, preorder, postorder);
        root->right = construct(preIndex, leftSubtreeRootIndex + 1, postEnd - 1, preorder, postorder);
        
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preIndex = 0;
        return construct(preIndex, 0, postorder.size() - 1, preorder, postorder);
    }
};