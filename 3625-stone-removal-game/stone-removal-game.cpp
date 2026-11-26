class Solution {
public:
    bool canAliceWin(int n) {
        bool isbob = false;
        int curr =10;
        while(n>=curr){
            n-=curr;
            curr--;
            isbob = !isbob;
        }

        return isbob;
    }
};