class Solution {
private:
    vector<int>res;
    int MIN = INT_MAX;
    int MAX = INT_MIN;
    int n;
public:
    vector<int> findMissingElements(vector<int>& nums) {
        set<int>st(nums.begin(),nums.end());
        n = nums.size();
        for(int i=0;i<n;i++){
            MIN=min(MIN,nums[i]);
            MAX=max(MAX,nums[i]);
        }

        for(int i=MIN+1;i<MAX;i++){
            if(st.count(i)==0) res.push_back(i);
        }

        return res;
    }
};