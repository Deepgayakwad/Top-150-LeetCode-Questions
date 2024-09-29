class Solution {
public:
    bool isPalindrome(string s) {

        string name="";
         int n=s.length();
        int i=0;

        for(int i=0;i<n;i++){
            if(isalnum(s[i])){
                name+=tolower(s[i]);
            }
        }

        int left=0;
        int right=name.size()-1;

        while(left<right){
            if(name[left]==name[right]){
                left++;
                right--;
            }
            else{
                return false;
            }

            
        } 

        return true;
    }
};