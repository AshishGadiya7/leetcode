class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int,int>m;
        vector<int>query=queries;
        sort(intervals.begin(),intervals.end());
        sort(queries.begin(),queries.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        int j=0;
        vector<int>res(queries.size(),-1);
        for(int i=0;i<queries.size();i++){
              while(j<intervals.size()){
                if(intervals[j][0]<=queries[i]){
                    q.push({intervals[j][1]-intervals[j][0]+1,intervals[j][1]});
                }else break;
                j++;
              }
              while(!q.empty() && q.top().second<queries[i]){
                q.pop();
              }
              if(!q.empty()){
                m[queries[i]]=q.top().first;
              }else{
                m[queries[i]]=-1;
              }
               
        }
        for(int i=0;i<query.size();i++){
            res[i]=m[query[i]];
        }return res;
    }
};