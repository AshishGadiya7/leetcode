class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,vector<int>>start;
        unordered_map<int,vector<int>>end;
        int n=trips.size();
        for(int i=0;i<n;i++){
             int passcap=trips[i][0];
             int startpoint=trips[i][1];
             int endpoint=trips[i][2];
             start[startpoint].push_back(passcap);
             end[endpoint].push_back(passcap);
        }
        int temp=0;
        int j=0;
        for(auto a:start){
            for(int i=j;i<=a.first;i++){
            vector<int>cap=end[i];
            for(int k=0;k<cap.size();k++){
                temp-=cap[k];
            }}j=a.first+1;
            
             vector<int>cap=a.second;
             for(int i=0;i<cap.size();i++){
                temp+=cap[i];
             }
             if(temp>capacity)return false;
        }
        return true;

        
    }
};