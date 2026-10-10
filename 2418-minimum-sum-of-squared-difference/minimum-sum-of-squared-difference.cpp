class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<int> countDiff(100001,0);

        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            countDiff[diff]++;
        }
        int k = k1+k2;
        for(int i=countDiff.size()-1;i>0 && k>0 ;i--){
            int minOpe = min(countDiff[i],k);
            if(countDiff[i]>0){
                countDiff[i] -= minOpe;
                countDiff[i-1] += minOpe;
                k-=minOpe;
            }
        }

        long long ans = 0;
        for (int d=1;d<countDiff.size();d++) {
            ans += 1LL * countDiff[d] * d * d;
        }

        return ans;
    }
};