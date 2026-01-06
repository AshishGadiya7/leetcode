class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        vector<int>res(m);
        vector<int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
              prefix[i]=prefix[i-1]+nums[i];
        }
        for(int i=0;i<m;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                    if((prefix[j])<=queries[i]){
                        
                        temp++;
                    }else break;
            }
            res[i]=temp;
        }return res;
    }
};