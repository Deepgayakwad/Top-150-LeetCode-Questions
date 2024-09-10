class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0,end=nums.size()-1;
        int ans=-1;

        while(start<=end){
            int mid=start+(end-start)/2;

            // case 1 when target is mid
            if(nums[mid]==target){
                return mid;
            }
            // check which part is sorted
            if(nums[start]<=nums[mid]){
                // left part is sorted
                 
                if(nums[start]<=target && target<nums[mid]){
                   end=mid-1;
                }
                else{
                   start=mid+1;
                }
            }
            else{
                // right part is sorted
                
                if(nums[mid]<target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
                
            }
        }
       return -1;
    }
};