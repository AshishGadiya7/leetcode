class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>q;
        q.push(a);
        q.push(b);
        q.push(c);
        int res=0;
        while(!q.empty()){
            int temp=q.top();
            q.pop();
            int temp2=q.top();
            q.pop();
            temp--,temp2--;
            res++;
            if(temp2!=0)q.push(temp2);
            if(temp!=0)q.push(temp);
            if(q.size()<=1)break;
        }
        return res;
    }
};