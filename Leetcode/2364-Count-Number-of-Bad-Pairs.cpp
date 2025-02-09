class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int>value_freq;
        long long count=0;
        long long n=nums.size();
        for(int i=0;i<nums.size();i++){
            int num=nums[i]-i;
            count=count+value_freq[num];
            value_freq[num]++;
        }
        long long pairs=n*(n-1)/2;
        return pairs-count;
    }
};