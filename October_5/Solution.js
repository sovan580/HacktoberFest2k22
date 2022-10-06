var addOneRow = function(root, val, depth) {
  if (depth === 1) {
    return new TreeNode(val, root, null)
  }
  
  dfs(root, val, depth, 1)
  return root
};

var dfs = function(node, val, depth, currentDepth) {
    if (!node) return;
  
    if (currentDepth + 1 === depth) {
      node.left = new TreeNode(val, node.left, null)
      node.right = new TreeNode(val, null, node.right)
    }
  
    dfs(node.left, val, depth, currentDepth + 1)
    dfs(node.right, val, depth, currentDepth + 1)
}
