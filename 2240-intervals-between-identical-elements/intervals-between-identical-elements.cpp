class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
           unordered_map<int,vector<long long>>mp;
           int n=arr.size();
           for(int i=0;i<n;i++){
                 mp[arr[i]].push_back(i);
           }
           vector<long long>ans(n,0);
           for(auto a:mp){
                 int  key=a.first;
                 vector<long long>temp=a.second;
                 long long sum=0;
                 int s=temp.size();
                 for(int i=0;i<s;i++){
                      ans[temp[i]]+=abs((temp[i]*i)-sum);
                      sum+=temp[i];
                 }
                 sum=0;
                 for(int i=s-1;i>=0;i--){
                    ans[temp[i]]+=abs(temp[i]*(s-1-i)-sum);
                    sum+=temp[i];
                 }
           }return ans;
    }
};