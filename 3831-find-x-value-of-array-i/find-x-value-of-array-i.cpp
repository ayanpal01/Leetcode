class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> res(k,0);
        vector<long long>pre(k,0);

        for(int i=0;i<n;i++){

            vector<long long>curr(k,0);
            int rem = nums[i]%k;
            curr[rem]++;

            for(int oldrem=0;oldrem<k;oldrem++){
                int newrem = ((long long)oldrem*nums[i]%k)%k;
                curr[newrem] += pre[oldrem];
            }

            pre = move(curr);

            for(int x=0;x<k;x++) res[x]+=pre[x];
        }
        return res;

    }
};