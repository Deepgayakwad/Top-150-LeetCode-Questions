class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      
      vector<vector<int>>ans;
      if(!root) return ans;    // if root==NULL return ans;
      bool LtoRdir=true;
      queue<TreeNode*>q;

    //   step1 push root of tree in queue
      q.push(root);

        while(!q.empty()){
            // while queue is not equal to empty 
            int width=q.size();
            vector<int>oneLevel(width);

            for(int i=0;i<width;++i){
                TreeNode* frontNode=q.front();
                q.pop();

                int index=LtoRdir ? i: width-i-1;
                oneLevel[index]=frontNode->val;

                if(frontNode->left!=NULL){
                    q.push(frontNode->left);
                }
                if(frontNode->right!=NULL){
                    q.push(frontNode->right);
                }
            }
            LtoRdir=!LtoRdir;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};
