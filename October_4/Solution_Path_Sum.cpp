class Solution {
    bool hasSum(TreeNode* root, int targetSum) {
        if(root == 0) {
            return false;
        }
        targetSum-=root->val;
        if(targetSum == 0 && root->left == 0 && root->right ==0) {
            return true;
        }
        return hasSum(root->left, targetSum)
            || hasSum(root->right, targetSum);
        
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasSum(root, targetSum);
    }
};
