class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int>freq;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                freq[nums[i]*nums[j]]++;
            }
        }
        map<int,int>::iterator it;
        int count=0;
        for(it=freq.begin();it!=freq.end();it++){
            count=count+8*((it->second)*(it->second-1))/2;
        }
        return count;
    }
};