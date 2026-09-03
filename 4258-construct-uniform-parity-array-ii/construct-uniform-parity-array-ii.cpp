class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int Min = nums1[0];
        bool odd = false;

        for(int num : nums1){
            Min = min(num,Min);
            if(num%2==1) odd = true;
        }

        if(Min%2==1) return true;
        return !odd;
    }
};