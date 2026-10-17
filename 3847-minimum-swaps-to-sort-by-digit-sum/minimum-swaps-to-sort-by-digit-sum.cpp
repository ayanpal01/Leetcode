class Solution {
    int digit(int n){
        int sum = 0;
        while(n!=0){
            int d = n%10;
            sum+=d;
            n/=10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int>digitSum(n,0);
        
        for(int i=0;i<n;i++){
            digitSum[i]=digit(nums[i]);
        }

        vector<int> indices(n);
        iota(indices.begin(), indices.end(), 0);
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            if (digitSum[a] != digitSum[b]) {
                return digitSum[a] < digitSum[b];
            }
            return nums[a] < nums[b];
        });

        vector<int> targetPos(n);
        for (int pos = 0; pos < n; pos++) {
            targetPos[indices[pos]] = pos;
        }

        vector<int> visited(n);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cycles++;
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = targetPos[j];
                }
            }
        }

        return n - cycles;
    }
};