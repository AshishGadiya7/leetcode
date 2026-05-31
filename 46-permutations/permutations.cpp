class Solution {
public:
    void compute(vector<vector<int>>& res, vector<int>& v, vector<int>& nums) {
        if (v.size() == nums.size()) {
            res.push_back(v);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (find(v.begin(), v.end(), nums[i]) == v.end()) {
                v.push_back(nums[i]);
                compute(res, v, nums);
                v.pop_back();   
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        compute(res, temp, nums);
        return res;
    }
};