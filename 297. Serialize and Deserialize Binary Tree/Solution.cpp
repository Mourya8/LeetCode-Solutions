/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

   string serialize(TreeNode* root) {
        string  s = "";
        if(!root) return s;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode * temp = q.front();
            q.pop();
            if(!temp) s.append("null,");
            else{
            s.append(to_string(temp->val)+ ",");
            q.push(temp->left);
            q.push(temp->right);
            }
        }
        return s;
    }
    // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
    //     queue<TreeNode*> q;
    //     string r="";
    //     if(root==NULL)
    //     {
    //         return r;
    //     }
    //     r=r+to_string(root->val)+',';
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         TreeNode* temp= q.front();
    //         q.pop();
    //         if(temp->left!=NULL)
    //         {
    //             q.push(temp->left);
    //             r=r+to_string(temp->left->val)+',';
    //         }
    //         else
    //         {
    //             r=r+"null,";
    //         }
    //         if(temp->right!=NULL)
    //         {
    //             q.push(temp->right);
    //             r=r+to_string(temp->right->val)+',';
    //         }
    //         else
    //         {
    //             r=r+"null,";
    //         }
    //     }
    //     //cout<<r<<endl;
    //     return r;

    // }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
        {
            return NULL;
        }
        queue <TreeNode*> q;
        vector <int> v;
        string t="";
        string y="";
        int j=0;
        while(data[j]!=',')
        {
            t=t+data[j];
            j++;
        }
        TreeNode* root=new TreeNode(stoi(t));
        t="";
        q.push(root);
        j++;
        for(int i=j;i<data.size();i++)
        {
            if(t!=""&&y!=""&&data[i]==',')
            {

               // cout<<t<<" "<<y<<endl;
                TreeNode* temp= q.front();
            q.pop();
            if(t!="null")
            {
                temp->left=new TreeNode(stoi(t));
                //cout<<temp->left->val<<endl;
                q.push(temp->left);
            }
            else{
                temp->left=NULL;
            }
            if(y!="null")
            {
                temp->right=new TreeNode(stoi(y));
                //cout<<temp->right->val<<endl;
                q.push(temp->right);
            }
            else{
                temp->right=NULL;
            }
                t="";
                y="";
                //i++;
            }
            else if(y==""&&data[i]!=','){
                t=t+data[i];
            }
            else
            {
                if(data[i]==',')
                {
                    i++;
                }
                y=y+data[i];
            }
        }
     
        //inOrderTraversal(root);
        return root;
    }
};



// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));