class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 1;

        int minIdx = 0;
        int maxIdx = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx])
                minIdx = i;

            if (nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        int a = min(minIdx, maxIdx);
        int b = max(minIdx, maxIdx);

        // 1. Both from front
        int front = b + 1;

        // 2. Both from back
        int back = n - a;

        // 3. One from front, one from back
        int both = (a + 1) + (n - b);

        return min({front, back, both});
    }
};