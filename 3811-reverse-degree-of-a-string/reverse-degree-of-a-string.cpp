class Solution {
public:
    int reverseDegree(string s) {
        int degree = 0;

        for (int i = 0; i < s.size(); i++) {
            int rev = 26 - (s[i] - 'a');
            degree += rev * (i + 1);
        }

        return degree;
    }
};