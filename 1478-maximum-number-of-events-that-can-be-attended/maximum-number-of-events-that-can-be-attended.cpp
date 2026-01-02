class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        int i=0;
        int count=0,day;
        day=events[0][0];
        int n=events.size();
        while(!pq.empty() || i<n){
            
            while(i<n && day==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                count++;
            }
            while(!pq.empty() && pq.top()<=day){
                pq.pop();
            }
            day++;
        }return count;
    }
};