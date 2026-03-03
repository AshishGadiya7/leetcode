class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        int n=stones.size();
        for(int i=0;i<n;i++){
            q.push(stones[i]);
        }
        while(!q.empty() && q.size()>1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            if(a>b){
                q.push(a-b);
            }else if(b>a){
                q.push(b-a);
            }
        }
        if(!q.empty()){
            return q.top();
        }return 0;
    }
};