class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int maxele = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        if(n==k) return maxele;

        vector<int>freq(maxele+1,0);

        for(int num:nums) freq[num]++;

        int ans = -1;
        if(k==1){
            for(int x:nums){
                if(freq[x]==1) ans = max(ans,x);
            }
            return ans;
        }

        if(freq[nums[0]]==1) ans = max(ans,nums[0]);
        if(freq[nums[n-1]]==1) ans = max(ans,nums[n-1]);

        return ans;
    }
};