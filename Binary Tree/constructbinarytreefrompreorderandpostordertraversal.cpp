class Solution {
public:

     void createMapping(vector<int>& inorder,int size,map<int,int>&valueToIndexMap){

        for(int i=0;i<size;i++){
            int element=inorder[i];
            int index=i;

            valueToIndexMap[element]=index;

            
        }
     }
    //   int searchInOrder(vector<int>& inorder,int size,int element){
    //       for(int i=0;i<size;i++){
    //          if(inorder[i]==element){
    //             return i;
    //          }
    //       }
    //       return -1;
    //   }

       TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,int& preIndex, int preOrderedStart,int preOrderedEnd ,int size, map<int,int>&valueToIndexMap) {

        //   base case
            if(preIndex>=size || preOrderedStart>preOrderedEnd){
                return NULL;
            }

            // element create karo
            int element=preorder[preIndex];
            preIndex++;

            // node create karo
            TreeNode* root=new TreeNode(element);

            // int position=searchInOrder(inorder,size,element);
            int position=valueToIndexMap[element];


            root->left=constructTree(preorder,inorder,preIndex,preOrderedStart,position-1,size,valueToIndexMap);
             root->right=constructTree(preorder,inorder,preIndex,position+1,preOrderedEnd,size,valueToIndexMap);

             return root;

       }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex=0;
        int preOrderdStart=0;
      
        int size=preorder.size();
        int preOrderedEnd=size-1;
        map<int,int>valueToIndexMap;
      
       
        createMapping(inorder,size,valueToIndexMap);

       TreeNode* rootmain=constructTree(preorder,inorder,preIndex,preOrderdStart,preOrderedEnd,size,valueToIndexMap);
        return rootmain;
    }
};