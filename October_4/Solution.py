class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if root==None:
            return False
                                    
        targetSum=targetSum-root.val
                                                    
        if root.left==None and root.right==None:
            return targetSum==0
                                                                                
        return self.hasPathSum(root.left,targetSum) or self.hasPathSum(root.right,targetSum)
