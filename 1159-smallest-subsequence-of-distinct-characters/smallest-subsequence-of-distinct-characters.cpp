class Solution {
public:
    string smallestSubsequence(string s) {
        
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        stack<char>sta;
        vector<int>visited(26,0);
        for(int i=0;i<n;i++){
            if(!visited[s[i]-'a']){
                 while(!sta.empty()){
                    if(mp[sta.top()]!=0 && sta.top()>s[i]){
                        visited[sta.top()-'a']=0;
                        sta.pop();
                    }else{
                        visited[s[i]-'a']=1;
                        sta.push(s[i]);
                        break;
                    }
                 }
                 if(sta.empty()){
                    visited[s[i]-'a']=1;
                    sta.push(s[i]);
                 }mp[s[i]]--;

            }else{
                mp[s[i]]--;
            }
        }
        string res="";
        while(!sta.empty()){
            res+=sta.top();
            sta.pop();
        }reverse(res.begin(),res.end());
        return res;
    }
};