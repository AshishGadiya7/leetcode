class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result=1,inc=1,dec=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                dec++;
                inc=1;
                result=max(result,dec);
            }else if(nums[i]<nums[i+1]){
                inc++;
                dec=1;
                result=max(result,inc);
            }else{
                inc=1;
                dec=1;
            }
        }return result;
    }
};