class Solution {
public:
    int count(TreeNode*root,int& cnt){
           if(root==NULL) return 0;
           cnt+=1;
            count(root->left,cnt);
           count(root->right,cnt);

           return cnt;

    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int cnt=0;

        int mainAns=count(root,cnt);
        return mainAns;
        
    }
};