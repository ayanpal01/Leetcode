class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string res = "", curr = "";
        for(char c: s){
            curr+=c;
            
            if(c=='(') st.push(c);
            else st.pop();

            if(st.empty()){
                res += curr.substr(1,curr.length()-2);
                curr = "";
            }
        }

        return res;
    }
};