public class Solution {
    public bool HasPathSum(TreeNode root, int targetSum) {
        return dfs(root, targetSum);
    }
    public bool dfs(TreeNode root, int target){
        if(root == null){
            return false;
        }
        int newTarget = target-root.val;
        if(newTarget == 0 && root.left == null && root.right ==null){
            return true;
        }
        return dfs(root.left, newTarget) || dfs(root.right, newTarget);
    }
}
