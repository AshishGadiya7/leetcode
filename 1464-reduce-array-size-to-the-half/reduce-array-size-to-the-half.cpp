class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }

        priority_queue<pair<int,int>>q;
        for(auto a:mp){
            q.push({a.second,a.first});
        }
        int count=0,temp=0;
        while(!q.empty() && temp<(n/2)){
            count++;
            temp+=q.top().first;
            q.pop();
        }return count;
    }
};