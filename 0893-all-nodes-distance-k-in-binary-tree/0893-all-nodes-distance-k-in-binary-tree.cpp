/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node ->left != nullptr){
                q.push(node->left);
                parents[node->left] = node;
            } 
            if(node->right != nullptr){
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parents;
        markParents(root,parents);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int lvl = 0;
        while(!q.empty()){
            int n = q.size();
            if(lvl == k){
                break;
            }
            lvl++;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right != nullptr && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parents[node] && !visited[parents[node]]){
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};