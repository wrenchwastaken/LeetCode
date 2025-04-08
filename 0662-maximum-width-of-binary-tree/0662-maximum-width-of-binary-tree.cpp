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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int ans = 0;
        queue<pair<TreeNode*, unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
            unsigned long long first, last;
            unsigned long long mini = q.front().second;
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front().first;
                unsigned long long curr = q.front().second - mini;
                q.pop();
                if(i == 0){
                    first = curr;
                }
                if(i == n-1){
                    last = curr;
                }
                if(node->left != nullptr){
                    q.push({node->left, curr*2+1});
                }
                if(node->right != nullptr){
                    q.push({node->right, curr*2+2});
                }
            }
            ans = max(ans, static_cast<int>(last-first+1));
        }
        return ans; 
    }
};