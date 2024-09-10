class Solution {
public:
   int maximumPathsum(TreeNode* root,int &maxi){
    //   base case
         if(root==NULL) return 0;

         int leftSum=max(0,maximumPathsum(root->left,maxi));
         int rightSum=max(0,maximumPathsum(root->right,maxi));
         maxi=max(maxi,leftSum+rightSum+root->val);

         return  max(leftSum,rightSum)+root->val;
   }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        maximumPathsum(root,maxi);
        return maxi;
        
    }
};