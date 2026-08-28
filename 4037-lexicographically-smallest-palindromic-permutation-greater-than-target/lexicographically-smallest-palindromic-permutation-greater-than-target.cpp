class Solution {
private:
    int half;
    char midChar = '$';
    string result;

    bool solve(string& curr, vector<int>& count, string& target,
               int i, bool greater) {

        // Left half is complete
        if (i == half) {
            string candidate = curr;

            // Add middle character for odd length
            if (midChar != '$') {
                candidate += midChar;
            }

            // Add reversed left half
            string rightHalf = curr;
            reverse(rightHalf.begin(), rightHalf.end());
            candidate += rightHalf;

            if (candidate > target) {
                result = candidate;
                return true;
            }

            return false;
        }

        // Try characters in lexicographical order
        for (char ch = 'a'; ch <= 'z'; ch++) {

            int idx = ch - 'a';

            if (count[idx] < 2) continue;

            // If prefix is equal, we cannot choose a smaller character
            if (!greater && ch < target[i]) continue;

            curr.push_back(ch);
            count[idx] -= 2;

            bool isGreater = greater || (ch > target[i]);

            if (solve(curr, count, target, i + 1, isGreater)) {
                return true;
            }

            curr.pop_back();
            count[idx] += 2;
        }

        return false;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;      
        int oddCount = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                oddCount++;
                midChar = char('a' + i);
            }
        }

        if (oddCount > 1) return "";

        half = n / 2;

        string curr = "";

        solve(curr, count, target, 0, false);

        return result;
    }
};