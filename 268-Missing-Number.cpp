class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(low==nums[low] && high==nums[high]){
                return high+1;
            }else if(mid==nums[mid]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }return low;
    }
};