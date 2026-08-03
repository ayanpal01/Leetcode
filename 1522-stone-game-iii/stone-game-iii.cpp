class Solution {
    int n;
    vector<int> values;
    vector<int> dp;

    int winner(int i) {
        if (i >= n) return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = 0;
        int ans = INT_MIN;

        for (int k = 0; k < 3 && i + k < n; k++) {
            take += values[i + k];
            ans = max(ans, take - winner(i + k + 1));
        }

        return dp[i] = ans;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
        values = stoneValue;
        n = values.size();

        dp.assign(n, INT_MIN);

        int diff = winner(0);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};