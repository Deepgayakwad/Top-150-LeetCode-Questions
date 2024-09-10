class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
         int n=s.size();

        for(int i=0;i<n;i++){
            // 1st check for open bracket or not
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                // it is close bracket 
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();

                if(s[i]==')' && ch=='(' || s[i]==']' && ch=='[' || s[i]=='}' && ch=='{'){

                }
                else{
                    return false;
                }
            }


        }
        return st.empty();
    }
};