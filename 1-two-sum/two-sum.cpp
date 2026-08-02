class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            auto ii=m.find(target-nums[i]);
            if(ii!=m.end()){
                return {ii->second,i};
            }else{
                m[nums[i]]=i;
            }
        }return {};
    }
};