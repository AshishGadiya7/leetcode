class Solution {
public:
    int compute(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        if (i < 0) {
            int res = 0;
            while (j >= 0) res += s2[j--];
            return res;
        }
        if (j < 0) {
            int res = 0;
            while (i >= 0) res += s1[i--];
            return res;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (s1[i] == s2[j]) {
            return dp[i][j] = compute(s1, s2, i - 1, j - 1, dp);
        }

        int del1 = s1[i] + compute(s1, s2, i - 1, j, dp);
        int del2 = s2[j] + compute(s1, s2, i, j - 1, dp);

        return dp[i][j] = min(del1, del2);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return compute(s1, s2, n - 1, m - 1, dp);
    }
};