class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0, sum2 = 0;
        for (int x : nums1) sum1 += x;
        for (int x : nums2) sum2 += x;
        if (nums1.size() * 6 < nums2.size() || nums2.size() * 6 < nums1.size())
            return -1;
        if (sum1 > sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }
        sort(nums1.begin(), nums1.end());        
        sort(nums2.rbegin(), nums2.rend());      
        int i = 0, j = 0, ops = 0;
        while (sum1 < sum2) {
            int inc = (i < nums1.size()) ? 6 - nums1[i] : 0;
            int dec = (j < nums2.size()) ? nums2[j] - 1 : 0;
            if (inc >= dec) {
                sum1 += inc;
                i++;
            } else {
                sum2 -= dec;
                j++;
            }
            ops++;
        }
        return ops;
    }
};
