class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int f[3] = {0, 0, 0};

        for (auto& s : stones) f[s % 3]++;

        if (f[0]%2 == 0) return f[1] > 0 && f[2] > 0;
        return abs(f[1]-f[2])>2;
    }
};