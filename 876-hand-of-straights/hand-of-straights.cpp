class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<hand.size();i++){
            q.push(hand[i]);
        }
        vector<int>v;
        while(!q.empty()){
            int pre=q.top();
            q.pop();
             for(int i=0;i<groupSize-1;i++){
                if(q.empty() && v.size()==0)return false;
                 while(!q.empty() && pre==q.top()){
                    v.push_back(pre);
                    q.pop();
                 }
                 if(pre!=q.top()-1)return false;
                 pre=q.top();
                 q.pop();
             }
             for(int i=0;i<v.size();i++){
                q.push(v[i]);
             }v.clear();
        }return true;

    }
};