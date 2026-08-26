class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i = 0;
        int ones = 0;

        string ans = "";

        for (int j=0;j<n;j++) {
            if (s[j]=='1') ones++;

            while (ones > k) {
                if (s[i] == '1') ones--;
                i++;
            }

            while (ones==k && s[i]=='0') i++;

            if (ones == k) {
                string sub = s.substr(i, j - i + 1);
                if (ans==""||sub.size() < ans.size() ||
                    (sub.size() == ans.size() && sub < ans)) {
                    ans = sub;
                }
            }
        }

        return ans;
    }
};