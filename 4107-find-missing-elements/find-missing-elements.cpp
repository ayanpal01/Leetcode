class Solution {
private:
    vector<int>res;
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            int next = nums[i]+1;
            while(next!=nums[i+1]){
                res.push_back(next);
                next++;
            }
        }
        return res;
    }
};