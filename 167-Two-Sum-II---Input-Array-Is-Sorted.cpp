class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low=0,high=numbers.size()-1,mid;
        vector<int>res;
        while(low<high){
            int sum=numbers[low]+numbers[high];
            if(sum==target){
                res.push_back(low+1);
                res.push_back(high+1);
                return res;
            }else if(sum>target){
                high--;
            }else{
                low++;
            }
        }res.push_back(low+1);
                res.push_back(high+1);
        return res;
    }
};