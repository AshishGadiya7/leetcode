class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int i = 0, j = 0;
        vector<int> pre(n, INT_MAX);
        int ans = INT_MAX;
        int sum = 0;

        while (i < n) {
            sum += arr[i];

            while (sum > target) {
                sum -= arr[j];
                j++;
            }

            if (sum == target) {
                int len = i - j + 1;

                if (j > 0 && pre[j - 1] != INT_MAX) {
                    ans = min(ans, len + pre[j - 1]);
                }

                pre[i] = len;
                if (i > 0) {
                    pre[i] = min(pre[i], pre[i - 1]);
                }
            }
            else {
                if (i > 0) {
                    pre[i] = pre[i - 1];
                }
            }

            i++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};