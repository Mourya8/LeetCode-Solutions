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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        map<int,TreeNode*> m;
        map<int,bool> check;
        TreeNode* temp;
        for( int i=0;i<d.size();i++)
        {
            if(m.find(d[i][0])!=m.end())
            {
                if(check.find(d[i][1])!=check.end())
                {
                    check.erase(d[i][1]);
                }
                temp=m[d[i][0]];
            }
            else
            {
                temp=new TreeNode(d[i][0]);
                m[d[i][0]]=temp;
                check[d[i][0]]=1;
                if(check.find(d[i][1])!=check.end())
                {
                    check.erase(d[i][1]);
                } 
            }
            if(d[i][2]==1)
                {
                    if(m.find(d[i][1])==m.end())
                    {
                        temp->left=new TreeNode(d[i][1]);
                        m[d[i][1]]=temp->left;
                    }
                    else{
                        temp->left=m[d[i][1]];
                    }
                }
                else
                {
                    if(m.find(d[i][1])==m.end())
                    {
                        temp->right=new TreeNode(d[i][1]);
                        m[d[i][1]]=temp->right;
                    }
                    else{
                        temp->right=m[d[i][1]];
                    }
                }
        }
        for (auto it = check.begin(); it != check.end(); ++it) 
        {
            //cout<<it->first<<endl;
            temp=m[it->first];
        }
        return temp;
    }
};