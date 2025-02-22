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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>nums;
        nums.push(root);
        vector<vector<int>>vec;
        if(root==NULL){
            return vec;
        }
        while(!nums.empty()){
            int n=nums.size();
            vector<int>temp;
            for(int i=0;i<n;i++){
                temp.push_back(nums.front()->val);
                if(nums.front()->left!=NULL){
                   nums.push(nums.front()->left);
                }
                if(nums.front()->right!=NULL){
                   nums.push(nums.front()->right);
                }
                nums.pop();
            }
            vec.push_back(temp);
        }
        return vec;
    }
};