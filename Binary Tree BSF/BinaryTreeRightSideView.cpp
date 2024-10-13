class Solution {
public:
        
       void printRightView(TreeNode* root,int level,vector<int>&rightView){

        //    base case 
           if(root==NULL) return;

           if(rightView.size()==level){
              rightView.push_back(root->val);
           }


        //    recursive call
            printRightView(root->right,level+1,rightView);
            printRightView(root->left,level+1,rightView);
       }

    vector<int> rightSideView(TreeNode* root) {
        vector<int>rightView;
        int level=0;

        printRightView(root,level,rightView);
        return rightView;
        
    }
};
