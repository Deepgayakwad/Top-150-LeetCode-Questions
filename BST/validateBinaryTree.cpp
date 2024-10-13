class Solution {
public:
    bool checkValid(TreeNode* root,long lb,long ub){
        if(root==NULL) return true; // empty tree is considered as BST

        if(root->val>lb  &&  root->val<ub){
            bool leftAns=checkValid(root->left,lb,root->val);
            bool rightAns=checkValid(root->right,root->val,ub);

            return leftAns && rightAns;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {

        long  int upperBound=LONG_MAX;
        long int lowerBound=LONG_MIN;

        bool ans=checkValid(root,lowerBound,upperBound);
        return ans;
        
    }
};