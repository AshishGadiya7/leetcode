class Solution {
public:
    int sumofdigit(int num){
        int sum=0;
        while(num){
            int i=num%10;
            sum=sum+i;
            num=num/10;
        }return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>key_value;
        
        for(int i=0;i<nums.size();i++){
            int num=sumofdigit(nums[i]);
            key_value[num].push_back(nums[i]);
        }
        int res=-1;
        for(auto &pair:key_value)
        {
            vector<int>&dummy=pair.second;
            if(dummy.size()>=2){
            sort(dummy.begin(),dummy.end());
            reverse(dummy.begin(),dummy.end());
            res=max(res,(dummy[0]+dummy[1]));
            }

        }
        return res;
    }
};