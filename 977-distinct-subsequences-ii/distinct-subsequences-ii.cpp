class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = (int)1e9+7;
        vector<int>count(26,0);
        long long sum = 0;
        for(char c : s){
            int total = (1+sum)%MOD;
            int idx = c-'a';
            sum = (sum + total - count[idx] + MOD) % MOD;
            count[idx]=total;
        }

        return (int)sum;
    }
};