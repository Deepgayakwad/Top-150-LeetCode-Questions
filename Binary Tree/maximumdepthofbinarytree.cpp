class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            // if node is not present then depth is zero 
           return 0;
        }

        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);

        int height=max(leftHeight,rightHeight)+1;
        // +1 is adding the height of root node

        return height;
    }
};