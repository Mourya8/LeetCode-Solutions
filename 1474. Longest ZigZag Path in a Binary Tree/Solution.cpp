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
    int maxCount = 0;

    void maxZigZag(TreeNode* root, int count, bool isLeft) {
        if (!root) return;
        maxCount = std::max(maxCount, count);
        if (isLeft) {
            maxZigZag(root->left, count + 1, false);
            maxZigZag(root->right, 1, true);
        } else {
            maxZigZag(root->right, count + 1, true);
            maxZigZag(root->left, 1, false);
        }
    }

    int longestZigZag(TreeNode* root) {
        maxZigZag(root, 0, true); // Start with the right child
        maxZigZag(root, 0, false); // Start with the left child
        return maxCount;
    }
};