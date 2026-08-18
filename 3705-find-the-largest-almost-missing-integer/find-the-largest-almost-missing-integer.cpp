class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i=0; i<=n-k; i++) {
            unordered_set<int> st;
            int j=i;
            while(j<i+k){
                st.insert(nums[j]);
                j++;
            }
            for (int x : st) mp[x]++;
        }

        int ans = -1;
        for (auto& [num, count] : mp) {
            if (count == 1) ans = max(ans, num);
        }

        return ans;
    }
};