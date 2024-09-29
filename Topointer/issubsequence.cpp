class Solution {
public:
    bool isSubsequence(string s, string t) {


        int left=0;
        int right=0;
        string ans="";

        while(right<t.size()){
             if(s[left]==t[right]){
                ans+=t[right];
                left++;
                right++;
             }
             else{
                right++;
             }
        }

        if(ans==s){
            return true;
        }
        return false;
    }
};