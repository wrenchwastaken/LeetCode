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
    //recursive function for preorder -> root->left->right
    void preorder(TreeNode* node, vector<int> &ans){
        //base case
        if(node == nullptr){
            return;
        }
        //put value for root of subtree
        ans.push_back(node->val);
        //go left
        preorder(node->left,ans);
        //go right
        preorder(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        //functional call for other recursive calls
        preorder(root,ans);
        return ans;
    }
};