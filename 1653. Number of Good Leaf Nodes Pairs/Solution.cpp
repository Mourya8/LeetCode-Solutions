class Solution {
public:

    int result = 0;

    vector<int> dfs(TreeNode* node, int distance) {
            if (!node) return {};
            if (!node->left && !node->right) return {0};
            
            vector<int> left_distances = dfs(node->left,distance);
            vector<int> right_distances = dfs(node->right,distance);
            
            for (int l : left_distances) {
                for (int r : right_distances) {
                    if (l + r + 2 <= distance) {
                        result++;
                    }
                }
            }
            
            vector<int> distances;
            for (int d : left_distances) distances.push_back(d + 1);
            for (int d : right_distances) distances.push_back(d + 1);
            
            return distances;
        }
    int countPairs(TreeNode* root, int distance) {
        
        dfs(root,distance);
        return result;
    }
};
