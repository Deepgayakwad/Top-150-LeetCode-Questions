class Solution {
public:
    void MapCreating(vector<int>& inorder,int size, map<int,int>&valueIndexToMap){

        for(int i=0;i<size;i++){
            int element=inorder[i];
              valueIndexToMap[element]=i;
        }
    }

     TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder,int& postIndex,int inOrderStart,int inOrderEnd,map<int,int>&valueIndexToMap){

        //    base case
         if(postIndex<0 || inOrderStart>inOrderEnd){
              return NULL;
         }

        //  element prepare karo
         int element=postorder[postIndex];
         postIndex--;

        //  create an node of that element
        
        TreeNode* root=new TreeNode(element);

        //  find the position of element in inorder array
        int position=valueIndexToMap[element];

        // recursion call 1st for right part then left part
        root->right=constructTree(inorder,postorder,postIndex,position+1,inOrderEnd,valueIndexToMap);
        root->left=constructTree(inorder,postorder,postIndex,inOrderStart,position-1,valueIndexToMap);

          return root;
     }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();

        int postIndex=size-1;
        int inOrderStart=0;
        int inOrderEnd=size-1;

        map<int,int>valueIndexToMap;
        MapCreating(inorder,size,valueIndexToMap);


        TreeNode* mainRoot=constructTree(inorder,postorder,postIndex,inOrderStart,inOrderEnd,valueIndexToMap);
           return mainRoot;
        
    }
};