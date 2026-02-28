class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>q;
        for(auto a:mp){
            q.push({a.second,a.first});
        }
        string res="";
        while(q.size()>1){
               pair<int,char>temp1=q.top();
               q.pop();
               pair<int,char>temp2=q.top();
               q.pop();
               res+=temp1.second;
               res+=temp2.second;
               temp1.first--;
               temp2.first--;
               if(temp1.first>0){
                q.push(temp1);
               }
               if(temp2.first>0){
                q.push(temp2);
               }
        }
        
        if(!q.empty()){
            auto temp=q.top();

            if(temp.first>1)
                return "";

            res+=temp.second;
        }
        
        return res;
    }
};