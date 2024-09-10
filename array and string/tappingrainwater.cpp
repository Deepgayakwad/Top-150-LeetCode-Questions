class Solution {
public:
    int trap(vector<int>& height) {

        int lMax=0,rMax=0,total=0;
       
        int left=0;
        int n=height.size();
        int right=n-1;

        while(left<right){
           if(height[left]<=height[right]){
            /* above term indicate that there is something  greater building on right
               can hold the water 
              */
                if(lMax>height[left]){
                total+=lMax-height[left];
                }
                else{
                // lMax is greater
                lMax=height[left];
               
               }
                 left+=1;
           }
           else{
               if(rMax>height[right]){
                   total+=rMax-height[right];
               }
               else{
                //   height[right] is greater
                   rMax=height[right];
                   
               }
                 right-=1;
           }
         }
        return total;
    }
};
          