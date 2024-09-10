class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int cnt=0;
        int ele;

        // iterate through the array and apply MVA(most voting algo)
        for(int i=0;i<nums.size();i++){
            if(cnt==0){
                cnt=1;
                ele=nums[i];
            }
            else if(ele==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }

        // checking in array how many times majority element is appear
        int cnt1=0;
        for(int i=0;i<nums.size();i++){
            if(ele==nums[i]){
                cnt1++;
            }
        }
        if(cnt1>nums.size()/2){
            return ele;
        }
        // if element is not present then return -1
        return -1;
    }
};