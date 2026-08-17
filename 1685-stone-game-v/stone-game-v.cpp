class Solution {
    int dp[501][501];

    int solve(int l, int r, vector<int>& cumSum) {
        if (l >= r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int score = 0;

        for (int mid = l; mid < r; mid++) {

            int leftSum = cumSum[mid] -
                          (l > 0 ? cumSum[l - 1] : 0);

            int rightSum = cumSum[r] - cumSum[mid];

            if (leftSum < rightSum) {

                score = max(
                    score,
                    leftSum + solve(l, mid, cumSum)
                );

            }
            else if (leftSum > rightSum) {

                score = max(
                    score,
                    rightSum + solve(mid + 1, r, cumSum)
                );

            }
            else {

                score = max({
                    score,
                    leftSum + solve(l, mid, cumSum),
                    rightSum + solve(mid + 1, r, cumSum)
                });
            }
        }

        return dp[l][r] = score;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {

        memset(dp, -1, sizeof(dp));

        int n = stoneValue.size();

        vector<int> cumSum(n);

        for (int i = 0; i < n; i++) {
            cumSum[i] = stoneValue[i] + (i > 0 ? cumSum[i - 1] : 0);
        }

        return solve(0, n - 1, cumSum);
    }
};