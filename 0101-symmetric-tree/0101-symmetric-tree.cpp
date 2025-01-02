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
    bool check(TreeNode* l, TreeNode* r){
        //check if either of them is null
        if(l==nullptr || r ==nullptr){
            return l==r;
        }
        //if data doesnt match
        if(l->val != r->val){
            return false;
        }
        //check for both further sides simultaneously
        return check(l->left,r->right) && check(l->right,r->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return check(root->left,root->right);
    }
};