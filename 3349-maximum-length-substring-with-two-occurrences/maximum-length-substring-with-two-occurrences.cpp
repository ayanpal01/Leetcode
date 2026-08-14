class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);
        int n = s.size();

        int i = 0, j = 0;
        int MAX = 0;

        while (j < n) {
            int idx = s[j] - 'a';
            count[idx]++;

            while (count[idx] > 2) {
                count[s[i] - 'a']--;
                i++;
            }

            MAX = max(MAX, j - i + 1);
            j++;
        }

        return MAX;
    }
};