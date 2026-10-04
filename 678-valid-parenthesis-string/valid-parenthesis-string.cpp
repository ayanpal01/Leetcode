class Solution {
public:
    bool checkValidString(string s) {
        if(s[0]==')') return false;

        int hold=0, valid=0;

        for(char c : s){
            valid += (c=='(')?1:-1;
            hold += (c!=')')?1:-1;

            if(hold<0) return false;
            valid = max(valid,0);
        }

        return valid==0;
    }
};