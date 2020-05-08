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
    
    int depth(TreeNode* root, int x, int ans){
        if(root == NULL){
            return 0;
        }
        if(root->val == x){
            return ans;
        }
        ans = max(depth(root->left, x, ans+1), depth(root->right, x, ans+1));
        return ans;
    }
    
    void check_cousin(TreeNode* root, int x, int y, int &res){
        if(root == NULL){
            return;
        }
        else if(root->left != NULL && root->right != NULL){
            if(root->left->val == x && root->right->val == y){
                res = 0;
                return;
            }
            if(root->left->val == y && root->right->val == x){
                res = 0;
                return;
            }
        }
        check_cousin(root->left, x,y,res);
        check_cousin(root->right, x,y,res);
        return;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        int ans = 0;
        int res = 1;
        ans = depth(root,x,ans);
        int ans1 = 0;
        ans1 = depth(root,y,ans1);
        if(ans != ans1){
            return 0;
        }
        check_cousin(root,x,y,res);
        return res;
    }
};
