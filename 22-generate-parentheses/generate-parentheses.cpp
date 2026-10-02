class Solution {
    vector<string>allPair;
    void solve(string s, int open, int close){
        if(open==0 && close==0){
            allPair.push_back(s);
        }
        if(open!=0){
            solve(s+'(',open-1,close);
        }
        if(open<close){
            solve(s+')',open,close-1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        solve("",n,n);
        return allPair;
    }
};