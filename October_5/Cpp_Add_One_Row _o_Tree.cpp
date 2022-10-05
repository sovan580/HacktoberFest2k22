class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* curr = new TreeNode(val, root, NULL);
            return curr;
        }
        int curr_depth = 2;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            
            if(depth == curr_depth){
                
                while(!q.empty()){
                    TreeNode* curr = q.front();
                    TreeNode* temp_left = new TreeNode(val,curr->left, NULL);
                    TreeNode* temp_right = new TreeNode(val, NULL, curr->right);
                    curr->left  = temp_left;
                    curr->right = temp_right;
                    q.pop();
                    
                }
                return root;
            }
            curr_depth++;
            
            int curr_size = q.size();
            while(curr_size--){
                TreeNode* curr= q.front();
                q.pop();
                if(curr->left!=NULL) q.push(curr->left);
                if(curr->right!=NULL) q.push(curr->right);
            }
            
        }
        
        return root;
        
    }
};
