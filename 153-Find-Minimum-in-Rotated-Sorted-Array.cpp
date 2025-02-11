class Solution {
public:
    int findMin(vector<int>& nums) {
        int high=nums.size()-1,low=0,mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[low]>nums[mid] && nums[high]>nums[mid]){
                low++,high--;
            }
           else if(nums[low]<=nums[mid] && nums[mid]<=nums[high]){
                return nums[low];
            }else if(nums[mid]>=nums[low]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }return nums[low];
    }
};