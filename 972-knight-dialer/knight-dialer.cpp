class Solution {
public:
    int mod = 1e9 + 7;

    int compute(int i, int n, vector<vector<int>>& dp) {
        if (n == 0) return 1;
        if (i == 5) return 0;

        if (dp[i][n] != -1) return dp[i][n];

        long long res = 0;

        if (i == 0) {
            res = (res + compute(4,n-1,dp)) % mod;
            res = (res + compute(6,n-1,dp)) % mod;
        }
        else if (i == 1) {
            res = (res + compute(6,n-1,dp)) % mod;
            res = (res + compute(8,n-1,dp)) % mod;
        }
        else if (i == 2) {
            res = (res + compute(7,n-1,dp)) % mod;
            res = (res + compute(9,n-1,dp)) % mod;
        }
        else if (i == 3) {
            res = (res + compute(4,n-1,dp)) % mod;
            res = (res + compute(8,n-1,dp)) % mod;
        }
        else if (i == 4) {
            res = (res + compute(0,n-1,dp)) % mod;
            res = (res + compute(3,n-1,dp)) % mod;
            res = (res + compute(9,n-1,dp)) % mod;
        }
        else if (i == 6) {
            res = (res + compute(0,n-1,dp)) % mod;
            res = (res + compute(1,n-1,dp)) % mod;
            res = (res + compute(7,n-1,dp)) % mod;
        }
        else if (i == 7) {
            res = (res + compute(2,n-1,dp)) % mod;
            res = (res + compute(6,n-1,dp)) % mod;
        }
        else if (i == 8) {
            res = (res + compute(1,n-1,dp)) % mod;
            res = (res + compute(3,n-1,dp)) % mod;
        }
        else if (i == 9) {
            res = (res + compute(2,n-1,dp)) % mod;
            res = (res + compute(4,n-1,dp)) % mod;
        }

        return dp[i][n] = (int)res;
    }

    int knightDialer(int n) {
        vector<vector<int>> dp(10, vector<int>(n, -1));
        long long sum = 0;

        for (int i = 0; i <= 9; i++) {
            sum = (sum + compute(i, n-1, dp)) % mod;
        }

        return (int)sum;
    }
};