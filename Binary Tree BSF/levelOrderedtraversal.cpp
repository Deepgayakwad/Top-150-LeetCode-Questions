class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        

        vector<vector<int>>levelStore;

        if(root==NULL) return levelStore;  // when tree is empty return empty vector
        vector<int>ans;

        queue<TreeNode*>q;

        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* front=q.front();
            q.pop();

            if(front==NULL){

                /* once when front==NULL means our level is complete then we push ans vector into our main vector
                 then make ans vector clear to store the output of next level  then if queue is not empty then push NULL 
                 into q when you push null it ensure that the next level all nodes are already present in queue */
                levelStore.push_back(ans);

              
                ans.clear();
                
                 
                if(!q.empty()) q.push(NULL);

            }
            else{
                // not NULL
                ans.push_back(front->val);
                if(front->left!=NULL)   q.push(front->left);
               
               if(front->right!=NULL) q.push(front->right);
            }
        }
        return levelStore;
    }
};