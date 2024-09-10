class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;

        
    //  if one node is null or another node is not null return false;
        if(p==NULL || q==NULL) return false;

        if(p->val!=q->val){
            return false;
        }

        bool leftAns=isSameTree(p->left,q->left);
        bool rightAns=isSameTree(p->right,q->right);

        return leftAns && rightAns;
    }
};