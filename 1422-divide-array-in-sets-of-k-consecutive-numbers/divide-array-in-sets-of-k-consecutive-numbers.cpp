class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        for(auto a:mp){
            int temp=a.first;
            while(mp[a.first]!=0){
                for(int i=0;i<k;i++){
                    if(mp[temp+i]>0)mp[temp+i]--;
                    else return false;
                }
            }
            
        }return true;
    }
};