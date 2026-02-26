class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        int i=-1,j=0;
        vector<int>res;
        int temp=INT_MIN;
        while(j<n){
               if(mp[s[j]] >j){
                 temp=max(temp,mp[s[j]]);
               }else{
                   if(temp<=mp[s[j]]){
                      res.push_back(j-i);
                      i=j;
                   }
               }j++;
        }return res;
    }
};