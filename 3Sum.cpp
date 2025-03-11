#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int num = nums.size();

        int i = num - 1;
        while (i >= 0) {
            // Move `pre = nums[i]` before the duplicate check
            int pre = nums[i];
            if (i != num - 1 && nums[i] == nums[i + 1]) {
                i--;
                continue;
            }

            int low = 0, high = i - 1;
            while (low < high) {
                int sum = nums[low] + nums[high] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[low], nums[high], nums[i]});
                    
                    // Skip duplicate values for `low`
                    while (low < high && nums[low] == nums[low + 1]) low++;
                    // Skip duplicate values for `high`
                    while (low < high && nums[high] == nums[high - 1]) high--;

                    low++;
                    high--;
                } else if (sum > 0) {
                    high--;
                } else {
                    low++;
                }
            }
            i--;
        }
        return res;
    }
};
