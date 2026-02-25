class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int temp=arr[i];
            int count=0;
            while(temp!=0){
                  if((temp&1)){
                     count++;
                  }temp=temp>>1;
            }
            mp[count].push_back(arr[i]);
        }
        vector<int>res;
        for( auto a:mp){
             vector<int>val=a.second;
             if(val.size()>1){
                 sort(val.begin(),val.end());
             }
             for(int i=0;i<val.size();i++){
                res.push_back(val[i]);
             }
        }return res;
    }
};