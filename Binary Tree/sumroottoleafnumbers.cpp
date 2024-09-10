class Solution {
public:
   int countSum(TreeNode* root,int sum){
       
       if(root==NULL) return 0;

       sum=sum*10+root->val;

       if(root->left==NULL && root->right==NULL) return sum;

       int leftAns=countSum(root->left,sum);
       int rightAns=countSum(root->right,sum);

       return leftAns+rightAns;
     }
    int sumNumbers(TreeNode* root) {

     int mainAns=countSum(root,0);
     return mainAns;
    }
};