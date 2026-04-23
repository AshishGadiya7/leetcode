class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target)return 0;
        int n=routes.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
               for(auto j:routes[i]){
                  mp[j].push_back(i);
               }
        }
        queue<int>q;
        vector<int>visited(n,0);
        vector<int>a=mp[source];
        for(auto i:a){
            q.push(i);
            visited[i]=1;
        }
        int count=1;
        while(!q.empty()){
            int s=q.size();
            while(s--){
             vector<int>temp=routes[q.front()];
             q.pop();
          
             for(auto i:temp){
                if(i==target)return count;
                vector<int>v=mp[i];
                for(auto j:v){
                    if(!visited[j]){
                        q.push(j);
                        visited[j]=1;
                    }
                }
             }}count++;
        }return -1;
    }
};