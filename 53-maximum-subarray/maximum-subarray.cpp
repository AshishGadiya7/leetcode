class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxsum=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
               sum+=nums[i];
               if(sum<nums[i])sum=nums[i];
                maxsum=max(sum,maxsum);
        }return maxsum;
    }
};