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
    int sumofpath(TreeNode* node, int &m){
        if(node == nullptr){
            return 0;
        }
        //calculate the lmax for the node
        int lmax = max(0,sumofpath(node->left,m));
        //calculate the rmax for the node
        int rmax = max(0,sumofpath(node->right,m));
        //calculate the max for that specific node
        m = max(m,lmax+rmax+node->val);
        //return which ever is the maximum
        return max(lmax,rmax)+node->val;
    }
    int maxPathSum(TreeNode* root) {
        int m = INT_MIN;
        sumofpath(root,m);
        return m;
    }
};