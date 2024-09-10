class Solution {
public:
   

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return NULL;

        // Swap the left and right children of the root
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        // Recursively invert the subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
