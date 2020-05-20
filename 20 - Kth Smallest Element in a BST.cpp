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
    
    void solve(TreeNode* root, int k, vector <int> &res){
        if(root == NULL){
            return;
        }
        solve(root->left,k,res);
        res.push_back(root->val);
        solve(root->right,k,res);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> res;
        solve(root,k,res);
        return res[k-1];
    }
};
