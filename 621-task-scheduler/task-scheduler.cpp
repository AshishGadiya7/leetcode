class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>q;
        unordered_map<char,int>m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        for(auto a:m){
            q.push(a.second);
        }
        int res=0;
        vector<int>v;
        while(!q.empty()){
            v.clear();
            for(int i=0;i<n+1;i++){
                if(!q.empty()){
                    int num=q.top()-1;
                    q.pop();
                    if(num>0)v.push_back(num);
                    
                }res++;
                if(q.empty() && v.size()==0)return res;
                
            }
            for(int i=0;i<v.size();i++){
                q.push(v[i]);
            }
        }return res;
        

    }
};