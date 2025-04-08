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
    TreeNode* markParentsandFindInf(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parents, int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* infectionpoint = new TreeNode(-1);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start){
                infectionpoint = node;
            }
            if(node->left){
                q.push(node->left);
                parents[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parents[node->right] = node;
            }
        }
        return infectionpoint;
    }
    int requiredTime(unordered_map<TreeNode*,TreeNode*>&parents, TreeNode* infectionpoint){
        queue<TreeNode*> q;
        q.push(infectionpoint);
        unordered_map<TreeNode*, bool> visited;
        visited[infectionpoint] = true;
        int timer = 0;
        while(!q.empty()){
            int n = q.size();
            int flag = 0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]){
                    flag = 1;
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    flag = 1;
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parents[node] && !visited[parents[node]]){
                    flag = 1;
                    visited[parents[node]] = true;
                    q.push(parents[node]);
                }
            }
            if(flag == 1){
                timer ++;
            }
        }
        return timer;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parents;
        TreeNode* infectionstart = markParentsandFindInf(root,parents,start);
        int time = requiredTime(parents,infectionstart);
        return time;
    }
};