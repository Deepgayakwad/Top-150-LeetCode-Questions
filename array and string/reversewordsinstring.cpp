class Solution {
public:
    string reverseWords(string s) {

        stack<string>wordstring;

        stringstream ss(s);
        string word="";
        string ans="";

        while(ss>>word){
            wordstring.push(word);
        }

        while(!wordstring.empty()){
            if(ans.size()==0){
                ans+=wordstring.top();
                wordstring.pop();
            }
            else{
                ans+=" ";
                ans+=wordstring.top();
                wordstring.pop();
            }
        }
        return ans;
    }
};
